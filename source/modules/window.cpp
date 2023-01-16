#include "window.h"

//To do: make 2 vboxes in grid, add entries and buttons to second
Window::Window()
: m_VBox(Gtk::Orientation::VERTICAL),
  m_VBox1(Gtk::Orientation::VERTICAL),
  m_VBox2(Gtk::Orientation::VERTICAL),
  m_VBox3(Gtk::Orientation::VERTICAL),
  m_Button_Submit("Add"),
  m_Button_Submit1("Update"),
  m_Button_Delete("Delete")
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

  m_Grid1.set_margin(5);

  m_Notebook.set_margin(5);

  m_Name1_Entry.set_margin(5);
  m_Price_Entry.set_margin(5);
  m_MaxQuantity_Entry.set_margin(5);
  m_Sales_Entry.set_margin(5);
  m_Purchases_Entry.set_margin(5);
  

  m_Name2_Entry.set_margin(5);
  m_Price1_Entry.set_margin(5);
  m_MaxQuantity1_Entry.set_margin(5);  
  m_Sales1_Entry.set_margin(5);
  m_Purchases1_Entry.set_margin(5);
  
  m_Descryption_Entry.set_margin(5);
  m_Descryption_Entry.set_size_request(-1,100);
  
  m_Descryption1_Entry.set_margin(5);
  m_Descryption1_Entry.set_size_request(-1,100);

  auto m_refTextBuffer = Gtk::TextBuffer::create();
  m_TextView.set_buffer(m_refTextBuffer);
  m_TextView.set_size_request(20,100);
  m_TextView.set_margin(10);
  
  //Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.set_child(m_TreeView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  m_ScrolledWindow.set_expand();

  //Append all elemnets to Vboxes
  m_VBox.append(m_ScrolledWindow);
  
  m_VBox1.append(m_Search_Label);
  m_VBox1.append(m_Name_Entry);
  m_VBox1.append(m_Notebook);

  m_VBox2.append(m_Name1_Label);
  m_VBox2.append(m_Name1_Entry);

  m_VBox2.append(m_Price_Label);
  m_VBox2.append(m_Price_Entry);

  m_VBox2.append(m_MaxQuantity_Label);
  m_VBox2.append(m_MaxQuantity_Entry);

  m_VBox2.append(m_Sales_Label);
  m_VBox2.append(m_Sales_Entry);

  m_VBox2.append(m_Purchases_Label);
  m_VBox2.append(m_Purchases_Entry);

  m_VBox2.append(m_Descryption_Label);
  m_VBox2.append(m_Descryption_Entry);

  m_VBox2.append(m_Button_Submit);

  m_VBox3.append(m_Name2_Label);
  m_VBox3.append(m_Name2_Entry);

  m_VBox3.append(m_Price1_Label);
  m_VBox3.append(m_Price1_Entry);

  m_VBox3.append(m_MaxQuantity1_Label);
  m_VBox3.append(m_MaxQuantity1_Entry);

  m_VBox3.append(m_Sales1_Label);
  m_VBox3.append(m_Sales1_Entry);

  m_VBox3.append(m_Purchases1_Label);
  m_VBox3.append(m_Purchases1_Entry);

  m_VBox3.append(m_Descryption1_Label);
  m_VBox3.append(m_Descryption1_Entry);
  //m_VBox3.append(m_TextView);

  m_VBox3.append(m_Grid1);


  //Make two Vboxes next to each other
  m_Grid.attach(m_VBox, 0, 0);
  m_Grid.attach(m_VBox1, 1, 0);

  //-------Create search bar-------

  m_Search_Label.set_text("Search by name:");
  m_Name_Entry.set_margin(5);
  m_Name_Entry.set_max_length(80);
;  m_Name_Entry.signal_changed().connect(sigc::mem_fun(*this, &Window::Search));

  //-------Create add, update form-------

  m_Name1_Label.set_text("Name:");
  m_Name1_Label.set_margin_start(5);
  m_Name1_Label.set_xalign(0);

  m_Price_Label.set_text("Price:");
  m_Price_Label.set_margin_start(5);
  m_Price_Label.set_xalign(0);

  m_MaxQuantity_Label.set_text("Max Quantity:");
  m_MaxQuantity_Label.set_margin_start(5);
  m_MaxQuantity_Label.set_xalign(0);


  m_Sales_Label.set_text("Sales:");
  m_Sales_Label.set_margin_start(5);
  m_Sales_Label.set_xalign(0);

  m_Purchases_Label.set_text("Purchases:");
  m_Purchases_Label.set_margin_start(5);
  m_Purchases_Label.set_xalign(0);
  
  m_Descryption_Label.set_text("Descryption:");
  m_Descryption_Label.set_margin_start(5);  
  m_Descryption_Label.set_xalign(0);

  m_Grid1.attach(m_Button_Submit1, 0, 0);
  m_Grid1.attach(m_Button_Delete, 1, 0);

//-------------------------------------------------

  m_Name2_Label.set_text("Name:");
  m_Name2_Label.set_margin_start(5);
  m_Name2_Label.set_xalign(0);

  m_Price1_Label.set_text("Price:");
  m_Price1_Label.set_margin_start(5);
  m_Price1_Label.set_xalign(0);

  m_MaxQuantity1_Label.set_text("Max Quantity:");
  m_MaxQuantity1_Label.set_margin_start(5);
  m_MaxQuantity1_Label.set_xalign(0);

  m_Quantity1_Label.set_text("Quantity:");
  m_Quantity1_Label.set_margin_start(5);
  m_Quantity1_Label.set_xalign(0);

  m_Sales1_Label.set_text("Sales:");
  m_Sales1_Label.set_margin_start(5);
  m_Sales1_Label.set_xalign(0);

  m_Purchases1_Label.set_text("Purchases:");
  m_Purchases1_Label.set_margin_start(5);
  m_Purchases1_Label.set_xalign(0);
  
  m_Descryption1_Label.set_text("Descryption:");
  m_Descryption1_Label.set_margin_start(5);  
  m_Descryption1_Label.set_xalign(0);

  m_ButtonBox_Submit.set_margin(5);
  m_Button_Submit.set_margin_bottom(5);
  m_Button_Submit.set_hexpand(true);
  m_Button_Submit.set_halign(Gtk::Align::CENTER);
  m_Button_Submit.signal_clicked().connect(
                  sigc::mem_fun(*this, &Window::SumbmitData));
                  //use to add item

  m_ButtonBox_Submit1.set_margin(5);
  m_Button_Submit1.set_margin_bottom(5);
  m_Button_Submit1.set_hexpand(true);
  m_Button_Submit1.set_halign(Gtk::Align::CENTER);
  m_Button_Submit1.signal_clicked().connect(
                  sigc::mem_fun(*this, &Window::UpdateData));
                  //use to add item
                  
  m_ButtonBox_Delete.set_margin(5);
  m_Button_Delete.set_margin_bottom(5);
  m_Button_Delete.set_hexpand(true);
  m_Button_Delete.set_halign(Gtk::Align::CENTER);
  m_Button_Delete.signal_clicked().connect(
                  sigc::mem_fun(*this, &Window::DeleteData));
                  //use to add item

  m_Notebook.append_page(m_VBox3, "Update");

  m_Notebook.append_page(m_VBox2, "Add");

  //-------Create the Tree model-------

  Elements.FillList();
  m_refTreeModel = Elements.GetListElements();
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

  auto selection = m_TreeView.get_selection();
  selection -> signal_changed().connect(sigc::mem_fun(*this, &Window::RowSelected));

}

Window::~Window(){}


void Window::Search(){
  m_id = selectedRowId;
  m_name = m_Name2_Entry.get_text();
  m_maxQuantity = m_MaxQuantity1_Entry.get_text();
  m_price = m_Price1_Entry.get_text();    
  m_sales = m_Sales1_Entry.get_text();
  m_purchases = m_Purchases1_Entry.get_text();
  m_descryption = m_Descryption1_Entry.get_text();

  std::string text = m_Name_Entry.get_text();
  m_refTreeModel->clear();
  Elements.FillList(text);
  m_refTreeModel = Elements.GetListElements();
}

void Window::SumbmitData(){
  std::string name = m_Name1_Entry.get_text();
  std::string price = m_Price_Entry.get_text();
  std::string maxQuantity = m_MaxQuantity_Entry.get_text();
  std::string sales = m_Sales_Entry.get_text();
  std::string purchases = m_Purchases_Entry.get_text();
  std::string descryption = m_Descryption_Entry.get_text();

  m_refTreeModel->clear();
  Elements.AddElement(name, price, maxQuantity, sales,
                      purchases, descryption);
  Search();
}

void Window::RowSelected(){
  //to do: make try, catch iter
  //if iter == none, display last selection
  Gtk::TreeModel::iterator iter = m_TreeView.get_selection() -> get_selected();
  int countSelected = m_TreeView.get_selection() -> count_selected_rows();
  

  if(countSelected != 0){ 
    Gtk::TreeModel::Row row = *iter;
  
    selectedRowId = row.get_value(m_Columns.m_col_id);
    m_Name2_Entry.set_text(row.get_value(m_Columns.m_col_name));
    m_MaxQuantity1_Entry.set_text(std::to_string(row.get_value(m_Columns.m_col_max_quantity)));
    m_Price1_Entry.set_text(std::to_string(row.get_value(m_Columns.m_col_price)));    
    m_Sales1_Entry.set_text(std::to_string(row.get_value(m_Columns.m_col_sales)));
    m_Purchases1_Entry.set_text(std::to_string(row.get_value(m_Columns.m_col_purchases)));
    m_Descryption1_Entry.set_text(row.get_value(m_Columns.m_col_descryption));
  }else{//if nothig is displayed on list, set last selected
    selectedRowId = m_id;
    m_Name2_Entry.set_text(m_name);
    m_MaxQuantity1_Entry.set_text(m_maxQuantity);
    m_Price1_Entry.set_text(m_price);    
    m_Sales1_Entry.set_text(m_sales);
    m_Purchases1_Entry.set_text(m_purchases);
    m_Descryption1_Entry.set_text(m_descryption);
  }
}

void Window::UpdateData(){
  if(selectedRowId != 0){
    int id = selectedRowId;
    std::string name = m_Name2_Entry.get_text();
    std::string maxQuantity = m_MaxQuantity1_Entry.get_text();
    std::string price = m_Price1_Entry.get_text();    
    std::string sales = m_Sales1_Entry.get_text();
    std::string purchases = m_Purchases1_Entry.get_text();
    std::string descryption = m_Descryption1_Entry.get_text();

    m_refTreeModel->clear();
    Elements.UpdateElement(id, name, price, maxQuantity,
                          sales, purchases, descryption);
    Search();
  }
}

void Window::DeleteData(){
  std::cout << selectedRowId << '\n';
  Elements.DeleteElement(selectedRowId);
  m_refTreeModel->clear();
  Search();
}
