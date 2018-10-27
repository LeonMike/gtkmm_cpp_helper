/*
  builder.hpp is part of gtkmm_cpp_helper.
  
  Foobar is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Foobar is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <gtkmm.h>
#include <map>

#define  GBUILDER          Gtk::Builder
#define  HLPBUILDER        gtkmm_cpp_helper::Builder
#ifndef RPTR
#define  RPTR(type)        Glib::RefPtr<type>
#endif

using namespace std;

namespace gtkmm_cpp_helper {

  struct STRUCT_WIDGET;
  
  typedef map<string, void*(*)> WIDGET_EVENT_CALLBACK_MAP;
  typedef pair<string, void*(*)> WIDGET_EVENT_CALLBACK_ITEM;

  typedef map<string, STRUCT_WIDGET> WIDGET_MAP;
  typedef pair<string, STRUCT_WIDGET> WIDGET_ITEM;

  struct STRUCT_WIDGET {
    union {
      Gtk::Widget *widget;
      Gtk::Dialog *dialog;
      Gtk::Window *window;
      //Gtk::ApplicationWindow *applicationWindow;
    };
    WIDGET_EVENT_CALLBACK_MAP events;
    WIDGET_MAP inner_widgets;
  };  
  
  class Builder {
  private:
    WIDGET_MAP      widgets;
    
  public:
    Builder();
    ~Builder();

    RPTR(GBUILDER)  gtkBuilder;
    
    void load_file(string filepath);

    STRUCT_WIDGET operator [] (string widget_name);
  };
  
}
