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

#include <launcher/window.hpp>
#include "widgets/main_menu.hpp"

#include <sdlgui/screen.h>
#include <sdlgui/window.h>
#include <sdlgui/layout.h>
#include <sdlgui/label.h>
#include <sdlgui/checkbox.h>
#include <sdlgui/button.h>
#include <sdlgui/toolbutton.h>
#include <sdlgui/popupbutton.h>
#include <sdlgui/combobox.h>
#include <sdlgui/dropdownbox.h>
#include <sdlgui/progressbar.h>
#include <sdlgui/entypo.h>
#include <sdlgui/messagedialog.h>
#include <sdlgui/textbox.h>
#include <sdlgui/slider.h>
#include <sdlgui/imagepanel.h>
#include <sdlgui/imageview.h>
#include <sdlgui/vscrollpanel.h>
#include <sdlgui/colorwheel.h>
#include <sdlgui/graph.h>
#include <sdlgui/tabwidget.h>
#include <sdlgui/switchbox.h>
#include <sdlgui/formhelper.h>
#include <memory>

#if defined(_WIN32)
#include <windows.h>
#endif
#include <iostream>

#if defined(_WIN32)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#if defined(_WIN32)
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

// Apparently it's required
using namespace sdlgui;

MainMenuWidget::MainMenuWidget(Screen* screen, SDL_Renderer* renderer, LauncherWindow* parent_window) :
  m_parent_window(parent_window)
{
  //bool bvar = false;
  //std::string strvar = "";
  //int ivar = 0;
  //float fvar = 0.0f;
  //double dvar = 0.0;
  
  /*
  FormHelper *gui = new FormHelper(screen);
  Window* nanogui_window = gui->addWindow(Vector2i(100, 100), "Form helper example");
  //gui->addGroup("Basic types");
  //gui->addVariable("bool", bvar);
  //gui->addVariable("string", strvar);

  //gui->addGroup("Validating fields");
  //gui->addVariable("int", ivar);
  //gui->addVariable("float", fvar);
  //gui->addVariable("double", dvar);

  //gui->addGroup("Complex types");
  //gui->addVariable("Enumeration", enumval, enabled)
  //   ->setItems({"Item 1", "Item 2", "Item 3"});
  //gui->addVariable("Color", colval);

  //gui->addGroup("Other widgets");
  gui->addButton("Launch SuperTux (last launched)", [](){ std::cout << "Button 1 pressed." << std::endl; });
  gui->addButton("Select SuperTux version...", [](){ std::cout << "Button 2 pressed." << std::endl; });

  screen->setVisible(true);
  screen->performLayout();
  nanogui_window->center();
  */



  auto& nwindow = screen->window("SuperTux Launcher v0.0.1", Vector2i{15, 15})
                    .withLayout<GroupLayout>();

  nwindow.button("Play SuperTux!", [] { std::cout << "pushed!" << std::endl; })
            .withTooltip("Lanches the last version of SuperTux you launched with the launcher");
  nwindow.button("Select version", [] { std::cout << "pushed!" << std::endl; })
            .withTooltip("Select which version you want to choose");
  nwindow.button("Manage versions", [] { std::cout << "pushed!" << std::endl; })
            .withTooltip("Add, remove or edit SuperTux versions");
  nwindow.button("Exit", [this] { m_parent_window->m_quit = true; })
            .withTooltip("Exit the launcher");

/*
  nwindow.label("Push buttons", "sans-bold")._and()
         .button("Plain button", [] { std::cout << "pushed!" << std::endl; })
            .withTooltip("This is plain button tips");

  nwindow.button("Styled", ENTYPO_ICON_ROCKET, [] { std::cout << "pushed!" << std::endl; })
           .withBackgroundColor( Color(0, 0, 255, 25) );

  nwindow.label("Toggle buttons", "sans-bold")._and()
         .button("Toggle me", [](bool state) { std::cout << "Toggle button state: " << state << std::endl; })
            .withFlags(Button::ToggleButton);

  nwindow.label("Radio buttons", "sans-bold")._and()
         .button("Radio button 1")
            .withFlags(Button::RadioButton);

  nwindow.button("Radio button 2")
            .withFlags(Button::RadioButton)._and()
         .label("A tool palette", "sans-bold");

  auto& tools = nwindow.widget().boxlayout(Orientation::Horizontal, Alignment::Middle, 0, 6);

  tools.toolbutton(ENTYPO_ICON_CLOUD)._and()
       .toolbutton(ENTYPO_ICON_FF)._and()
       .toolbutton(ENTYPO_ICON_COMPASS)._and()
       .toolbutton(ENTYPO_ICON_INSTALL);  

  nwindow.label("Popup buttons", "sans-bold")._and()
         .popupbutton("Popup", ENTYPO_ICON_EXPORT)
            .popup()
              .withLayout<GroupLayout>()
                 .label("Arbitrary widgets can be placed here")._and()
                 .checkbox("A check box")._and()
              .popupbutton("Recursive popup", ENTYPO_ICON_FLASH).popup()
                 .withLayout<GroupLayout>()
                   .checkbox("Another check box");
*/

  screen->performLayout(renderer);
  screen->centerWindow(static_cast<Window*>(&nwindow));
}

/* EOF */
