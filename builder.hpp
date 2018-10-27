#pragma once

#include <gtkmm.h>
#include <map>

#define  GBUILDER          Gtk::Builder
#define  HLPBUILDER        gtkmm_helper::Builder
#ifndef RPTR
#define  RPTR(type)        Glib::RefPtr<type>
#endif

using namespace std;

namespace gtkmm_helper {

  struct STRUCT_WIDGET;
  
  typedef map<string, void*(*)> WIDGET_EVENT_CALLBACK_MAP;
  typedef pair<string, void*(*)> WIDGET_EVENT_CALLBACK_ITEM;

  typedef map<string, STRUCT_WIDGET> WIDGET_MAP;
  typedef pair<string, STRUCT_WIDGET> WIDGET_ITEM;

  struct STRUCT_WIDGET {
    Gtk::Widget *widget;
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
  };
  
}
