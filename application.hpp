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

namespace gtkmm_helper {

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
    
  };

}
