/*
  application.hpp is part of gtkmm_cpp_helper.
  
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
#include <string>

#include <builder.hpp>

#define  GAPP              Gtk::Application
#ifndef RPTR
#define  RPTR(type)        Glib::RefPtr<type>
#endif

using namespace Gtk;
using namespace std;

namespace gtkmm_cpp_helper {

  typedef map<string, HLPBUILDER*>  BUILDER_MAP;
  typedef pair<string, HLPBUILDER*> BUILDER_ITEM;
  
  class Application {
  private:
    RPTR(GAPP) app;
    BUILDER_MAP            builders;
        
  public:
    Application(int argc, char **argv);
    ~Application();

    RPTR(GBUILDER) load_file(string key, string filepath);

    HLPBUILDER * operator [] (string key);
  };

}
