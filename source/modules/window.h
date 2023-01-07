#include <gtkmm.h>
#include <iostream>
#include <vector>
#include "columns.h"
#include "listElements.h"

#pragma once

using dataFrame = std::vector<std::vector<std::string>>;

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:
  //Signal handlers:
  void on_button_quit();
  void Search();
  void SumbmitData();


  listElements elements;
  ModelColumns m_Columns;

  //Child widgets:
  Gtk::Box m_VBox;
  Gtk::Box m_VBox1;
  Gtk::Grid m_Grid;

  Gtk::CellRendererText m_TextRenderer;
  Gtk::CellRendererText m_TextRenderer1;
  //To do: replace with vector of objects
  Gtk::TreeViewColumn m_TreeViewColumn;
  Gtk::TreeViewColumn m_TreeViewColumn1;
  Gtk::TreeViewColumn m_TreeViewColumn2;
  Gtk::TreeViewColumn m_TreeViewColumn3;
  Gtk::TreeViewColumn m_TreeViewColumn4;
  Gtk::TreeViewColumn m_TreeViewColumn5;
  Gtk::TreeViewColumn m_TreeViewColumn6;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

  Gtk::Box m_ButtonBox_Quit;
  Gtk::Button m_Button_Quit;
  Gtk::Box m_ButtonBox_Submit;
  Gtk::Button m_Button_Submit;

  Gtk::Entry m_Name_Entry;
};

