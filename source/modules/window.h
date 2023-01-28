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

private:
  int selectedRowId{1};

  //save last selected row
  int m_id;
  std::string m_name;
  std::string m_maxQuantity;
  std::string m_price;    
  std::string m_sales;
  std::string m_purchases;
  std::string m_description;

protected:
  //Signal handlers:
  void Search();
  void SumbmitData();
  void RowSelected();
  void UpdateData();
  void DeleteData();


  listElements Elements;
  ModelColumns m_Columns;

  //Child widgets:
  Gtk::Box m_VBox;
  Gtk::Box m_VBox1;
  Gtk::Box m_VBox2;
  Gtk::Box m_VBox3;
  Gtk::Grid m_Grid;
  Gtk::Grid m_Grid1;
  Gtk::Notebook m_Notebook;

  Gtk::CellRendererText m_TextRenderer;
  Gtk::CellRendererText m_TextRenderer1; //for different text alignment
  
  Gtk::TreeViewColumn m_TreeViewColumn;
  Gtk::TreeViewColumn m_TreeViewColumn7;
  Gtk::TreeViewColumn m_TreeViewColumn1;
  Gtk::TreeViewColumn m_TreeViewColumn2;
  Gtk::TreeViewColumn m_TreeViewColumn3;
  Gtk::TreeViewColumn m_TreeViewColumn4;
  Gtk::TreeViewColumn m_TreeViewColumn5;
  Gtk::TreeViewColumn m_TreeViewColumn6;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
  std::unique_ptr<Gtk::MessageDialog> m_pDialog;

  Gtk::Label m_Search_Label;
  Gtk::Label m_Label1;

//-------Add box-------
  Gtk::Label m_Name1_Label;
  Gtk::Label m_Price_Label;
  Gtk::Label m_MaxQuantity_Label;
  Gtk::Label m_Quantity_Label;
  Gtk::Label m_Sales_Label;
  Gtk::Label m_Purchases_Label;
  Gtk::Label m_Description_Label;

//-------Update box-------
  Gtk::Label m_Name2_Label;
  Gtk::Label m_Price1_Label;
  Gtk::Label m_MaxQuantity1_Label;
  Gtk::Label m_Quantity1_Label;
  Gtk::Label m_Sales1_Label;
  Gtk::Label m_Purchases1_Label;
  Gtk::Label m_Description1_Label;

//-------Add box-------
  Gtk::Box m_ButtonBox_Submit;
  Gtk::Button m_Button_Submit;

//-------Update box-------
  Gtk::Box m_ButtonBox_Submit1;
  Gtk::Button m_Button_Submit1;
  Gtk::Box m_ButtonBox_Delete;
  Gtk::Button m_Button_Delete;

  Gtk::Entry m_Name_Entry;

//-------Add box-------
  Gtk::Entry m_Name1_Entry;
  Gtk::Entry m_Price_Entry;
  Gtk::Entry m_MaxQuantity_Entry;
  Gtk::Entry m_Quantity_Entry;
  Gtk::Entry m_Sales_Entry;
  Gtk::Entry m_Purchases_Entry;
  Gtk::Entry m_Description_Entry;

//-------Update box-------
  Gtk::Entry m_Name2_Entry;
  Gtk::Entry m_Price1_Entry;
  Gtk::Entry m_MaxQuantity1_Entry;
  Gtk::Entry m_Quantity1_Entry;
  Gtk::Entry m_Sales1_Entry;
  Gtk::Entry m_Purchases1_Entry;
  Gtk::Entry m_Description1_Entry;
  Gtk::TextView m_TextView;
};
