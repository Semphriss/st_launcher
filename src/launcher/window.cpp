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
#include <GL/gl.h>

#include "util/log.hpp"

Window::Window()
{
}

bool
Window::show()
{
  SDL_Window* window;
  SDL_GLContext ctx;

  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("SuperTux Launcher",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            640,
                            400,
                            SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);

  if (window == NULL)
  {
    log_fatal << "Could not create SDL window : " << SDL_GetError() << std::endl;
    return false;
  }

  ctx = SDL_GL_CreateContext(window);
  SDL_GL_SetSwapInterval(1); // Sync with monitor's vertical refresh
  glClearColor(0.5,0.8,1.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(window);

  SDL_Delay(3000);

  SDL_DestroyWindow(window);

  SDL_Quit();

  return true;
}

/* EOF */
