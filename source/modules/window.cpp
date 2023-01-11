#include "window.h"



//To do: make 2 vboxes in grid, add entries and buttons to second
Window::Window()
: m_VBox(Gtk::Orientation::VERTICAL),
  m_VBox1(Gtk::Orientation::VERTICAL),
  //m_Button_Quit("Quit"),
  m_Button_Submit("Submit")
{
  set_title("Stocker");
  set_default_size(1000, 500);

  m_VBox.set_size_request(700, -1);
  m_VBox.set_margin(5);
  set_child(m_VBox);

  m_VBox1.set_size_request(300, -1);
  m_VBox1.set_margin(5);
  set_child(m_VBox1);

  m_Grid.set_margin(5);
  set_child(m_Grid);

  //Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.set_child(m_TreeView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  m_ScrolledWindow.set_expand();

  m_VBox.append(m_ScrolledWindow);
  m_VBox1.append(m_Name_Entry);
  m_VBox1.append(m_Button_Submit);
  //m_VBox1.append(m_ButtonBox_Quit);

  m_Grid.attach(m_VBox, 0, 0);
  m_Grid.attach(m_VBox1, 1, 0);

  m_Name_Entry.set_margin(5);
  m_Name_Entry.signal_changed().connect(sigc::mem_fun(*this, &Window::Search));

  m_ButtonBox_Submit.append(m_Button_Submit);
  m_ButtonBox_Submit.set_margin(5);
  m_Button_Submit.set_hexpand(true);
  m_Button_Submit.set_halign(Gtk::Align::CENTER);
  m_Button_Submit.signal_clicked().connect(sigc::mem_fun(*this, &Window::SumbmitData)); //use to submit chnged item

  // m_ButtonBox_Quit.append(m_Button_Quit);
  // m_ButtonBox_Quit.set_margin(5);
  // m_Button_Quit.set_hexpand(true);
  // m_Button_Quit.set_halign(Gtk::Align::CENTER);
  // m_Button_Quit.signal_clicked().connect( sigc::mem_fun(*this,
  //              &Window::on_button_quit) );

  //Create the Tree model:
  elements.FillList();
  m_refTreeModel = elements.GetListElements();
  m_TreeView.set_model(m_refTreeModel);

  //Fix alignment
  m_TextRenderer.set_property("xalign", 1.00);

  //Add the TreeView's view columns:
  //This number will be shown with the default numeric formatting.
  m_TreeViewColumn.pack_start(m_TextRenderer, true);
  m_TreeViewColumn.set_title("ID");
  m_TreeViewColumn.add_attribute(m_TextRenderer, "text", m_Columns.m_col_id);
  m_TreeViewColumn.set_sort_column(m_Columns.m_col_id);
  m_TreeView.append_column(m_TreeViewColumn);

  m_TreeView.append_column("Name", m_Columns.m_col_name);

  m_TreeViewColumn1.pack_start(m_TextRenderer, true);
  m_TreeViewColumn1.set_title("Price");
  m_TreeViewColumn1.add_attribute(m_TextRenderer, "text", m_Columns.m_col_price);
  m_TreeViewColumn1.set_sort_column(m_Columns.m_col_price);
  m_TreeView.append_column(m_TreeViewColumn1);

  m_TreeViewColumn2.pack_start(m_TextRenderer, true);
  m_TreeViewColumn2.set_title("Max Quantity");
  m_TreeViewColumn2.add_attribute(m_TextRenderer, "text", m_Columns.m_col_max_quantity);
  m_TreeViewColumn2.set_sort_column(m_Columns.m_col_max_quantity);
  m_TreeView.append_column(m_TreeViewColumn2);

  m_TreeViewColumn3.pack_start(m_TextRenderer, true);
  m_TreeViewColumn3.set_title("Quantity");
  m_TreeViewColumn3.add_attribute(m_TextRenderer, "text", m_Columns.m_col_quantity);
  m_TreeViewColumn3.set_sort_column(m_Columns.m_col_quantity);
  m_TreeView.append_column(m_TreeViewColumn3);

  m_TreeViewColumn4.pack_start(m_TextRenderer, true);
  m_TreeViewColumn4.set_title("Sales");
  m_TreeViewColumn4.add_attribute(m_TextRenderer, "text", m_Columns.m_col_sales);
  m_TreeViewColumn4.set_sort_column(m_Columns.m_col_sales);
  m_TreeView.append_column(m_TreeViewColumn4);

  m_TreeViewColumn5.pack_start(m_TextRenderer, true);
  m_TreeViewColumn5.set_title("Purchases");
  m_TreeViewColumn5.add_attribute(m_TextRenderer, "text", m_Columns.m_col_purchases);
  m_TreeViewColumn5.set_sort_column(m_Columns.m_col_purchases);
  m_TreeView.append_column(m_TreeViewColumn5);

  m_TreeViewColumn6.pack_start(m_TextRenderer1, true);
  m_TreeViewColumn6.set_title("Descryption");
  m_TreeViewColumn6.add_attribute(m_TextRenderer1, "text", m_Columns.m_col_descryption);
  m_TreeViewColumn6.set_sort_column(m_Columns.m_col_descryption);
  m_TreeViewColumn6.set_alignment(1.0);
  m_TreeViewColumn6.set_max_width(50);
  m_TreeView.append_column(m_TreeViewColumn6);

}

Window::~Window(){}

void Window::on_button_quit()
{
  hide();
}

void Window::Search(){
  std::string text = m_Name_Entry.get_text();
  m_refTreeModel->clear();
  elements.FillList(text);
  m_refTreeModel = elements.GetListElements();
  m_TreeView.set_model(m_refTreeModel);
}

void Window::SumbmitData(){
  //use database manager to change data in database
}