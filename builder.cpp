/*
  builder.cpp is part of gtkmm_cpp_helper.
  
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

#include <builder.hpp>

namespace gtkmm_cpp_helper {

  Builder::Builder() {
    gtkBuilder = Gtk::Builder::create();
  }

  Builder::~Builder() {
  }

  void Builder::load_file(string filepath) {
    gtkBuilder->add_from_file(filepath.c_str());
  }

  Gtk::Dialog * Builder::operator [] (string widget_name) {
    Gtk::Dialog *result;
    gtkBuilder->get_widget(widget_name, result);
    return result;
  }
  
}
