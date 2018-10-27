#include <builder.hpp>

namespace gtkmm_helper {

  Builder::Builder() {
    gtkBuilder = Gtk::Builder::create();
  }

  Builder::~Builder() {
  }

  void Builder::load_file(string filepath) {
    gtkBuilder->add_from_file(filepath.c_str());
  }
  
}
