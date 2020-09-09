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

#ifndef HEADER_STLAUNCHER_WIDGETS_MAINMENU_HPP
#define HEADER_STLAUNCHER_WIDGETS_MAINMENU_HPP

#include <SDL.h>
#include <sdlgui/screen.h>

#include <launcher/window.hpp>

class MainMenuWidget final
{
public:
  MainMenuWidget(sdlgui::Screen* screen, SDL_Renderer* renderer, LauncherWindow* parent_window);

  void show();
  void hide();

  bool is_visible();

private:
  LauncherWindow* m_parent_window;
};

#endif

/* EOF */
