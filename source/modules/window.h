#include <gtkmm.h>
#include <iostream>
#include <vector>

#pragma once

class Window : public Gtk::Window
{
public:
  Window();
  ~Window() override;

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Button m_button;
};

