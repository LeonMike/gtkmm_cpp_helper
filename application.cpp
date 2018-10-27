/*
  application.cpp is part of gtkmm_cpp_helper.
  
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

#include <application.hpp>

#include <iostream>

using namespace Gtk;
using namespace std;

namespace gtkmm_helper {

  Application::Application(int argc, char **argv) {
    cout << "now starting Application object" << endl;
    app     = GAPP::create(argc, argv);
    cout << "Application object started" << endl;
  }

  Application::~Application() {
  }

  RPTR(GBUILDER) Application::load_file(string key, string filepath) {
    cout << "now creating new builder" << endl;
    builders.insert(BUILDER_ITEM(key, new HLPBUILDER()));
    cout << "now loading .glade file" << endl;
    builders[key]->load_file(filepath);
    cout << "load completed" << endl;
    return builders[key]->gtkBuilder;
  }
  
}
