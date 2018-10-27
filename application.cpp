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
