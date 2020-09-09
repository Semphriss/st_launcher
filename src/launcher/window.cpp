//  SuperTux launcher
//  Copyright (C) 2020 A. Semphris <semphris@protonmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "launcher/window.hpp"

#include <SDL.h>
#include "SDL_image.h"
#include <sdlgui/screen.h>
#include <iostream>

#include "util/log.hpp"
#include "widgets/main_menu.hpp"

LauncherWindow::LauncherWindow() :
  m_quit(false)
{
}

bool
LauncherWindow::show()
{
  SDL_Window* window;
  SDL_GLContext ctx;

  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("SuperTux Launcher",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            640,
                            480,
                            SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);

  if (window == NULL)
  {
    log_fatal << "Could not create SDL window : " << SDL_GetError() << std::endl;
    return false;
  }

  ctx = SDL_GL_CreateContext(window);
  SDL_GL_SetSwapInterval(1); // Sync with monitor's vertical refresh
  SDL_GL_SwapWindow(window);

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  
  sdlgui::Screen *screen = new sdlgui::Screen(window, sdlgui::Vector2i(800, 600), "My Title");
  
  auto main_menu = MainMenuWidget(screen, renderer, this);
  
  SDL_Surface *image;
  image=IMG_Load("../data/images/bkg.png");
  if(!image) {
    printf("IMG_Load: %s\n", IMG_GetError());
    return false;
  }
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
  
  //SDL_SetWindowOpacity(window, 0.5);
  
  m_quit = false;
  try
  {
      SDL_Event e;
      while( !m_quit )
      {
          //Handle events on queue
          while( SDL_PollEvent( &e ) != 0 )
          {
              //User requests quit
              if( e.type == SDL_QUIT )
              {
                  m_quit = true;
              }
              screen->onEvent( e );
          }
          
          //SDL_SetRenderDrawColor(renderer, 0x80, 0xcd, 0xff, 0x00 );
          //SDL_RenderClear( renderer );
          
          SDL_RenderCopy(renderer, texture, NULL, NULL);
          SDL_RenderPresent(renderer);

          screen->drawAll();

          // Render the rect to the screen
          SDL_RenderPresent(renderer);

          //fps.next();
          SDL_Delay(30);
      }
  }
  catch (const std::runtime_error &e)
  {
      std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
      #if defined(_WIN32)
          MessageBoxA(nullptr, error_msg.c_str(), NULL, MB_ICONERROR | MB_OK);
      #else
          std::cerr << error_msg << std::endl;
      #endif
      return false;
  }

  SDL_DestroyWindow(window);

  SDL_Quit();

  return true;
}

/* EOF */
