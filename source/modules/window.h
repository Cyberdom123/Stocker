#include <gtkmm.h>
#include <iostream>
#include <vector>
#include "columns.h"
#include "listElements.h"

#pragma once

using dataFrame = std::vector<std::vector<std::string>>;

class Window : public Gtk::Window
{
public:
  Window();
  virtual ~Window();

protected:
  //Signal handlers:
  void on_button_quit();
  void Search();
  void SumbmitData();


  listElements Elements;
  ModelColumns m_Columns;

  //Child widgets:
  Gtk::Box m_VBox;
  Gtk::Box m_VBox1;
  Gtk::Box m_VBox2;
  Gtk::Box m_VBox3;
  Gtk::Grid m_Grid;
  Gtk::Notebook m_Notebook;

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

  Gtk::Label m_Search_Label;
  Gtk::Label m_Label1;
  Gtk::Label m_Name1_Label;
  Gtk::Label m_Price_Label;
  Gtk::Label m_MaxQuantity_Label;
  Gtk::Label m_Quantity_Label;
  Gtk::Label m_Sales_Label;
  Gtk::Label m_Purchases_Label;
  Gtk::Label m_Descryption_Label;

  Gtk::Box m_ButtonBox_Quit;
  Gtk::Button m_Button_Quit;
  Gtk::Box m_ButtonBox_Submit;
  Gtk::Button m_Button_Submit;

  Gtk::Entry m_Name_Entry;

  Gtk::Entry m_Name1_Entry;
  Gtk::Entry m_Price_Entry;
  Gtk::Entry m_MaxQuantity_Entry;
  Gtk::Entry m_Quantity_Entry;
  Gtk::Entry m_Sales_Entry;
  Gtk::Entry m_Purchases_Entry;
  Gtk::Entry m_Descryption_Entry;
};
