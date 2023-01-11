#include "listElements.h"
#include <iostream>

listElements::listElements(){
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
}

listElements::~listElements(){}

Glib::RefPtr<Gtk::ListStore> listElements::GetListElements() const { return m_refTreeModel;}

void listElements::FillList(std::string text){
    database.Create();
    dataFrame data = database.Search(text);
    //database.ReadAll();
    database.Close();


    for(auto a:data){
        auto row = *(m_refTreeModel->append());
        row[m_Columns.m_col_id] = std::stoi(a[0]);
        row[m_Columns.m_col_name] = a[1];
        row[m_Columns.m_col_price] = std::stof(a[2]);
        row[m_Columns.m_col_max_quantity] = std::stoi(a[3]);
        row[m_Columns.m_col_quantity] = std::stoi(a[4]);
        row[m_Columns.m_col_sales] = std::stoi(a[5]);
        row[m_Columns.m_col_purchases] = std::stoi(a[6]);
        row[m_Columns.m_col_descryption] = a[7];
    }
}

void listElements::AddElement(std::string fname, std::string fprice,
                    std::string fmaxQuantity, std::string fquantity, 
                    std::string fsales, std::string fpurchases, 
                    std::string fdescryption)
{
    std::string name = fname;
    float price = std::stof(fprice);
    int maxQuantity = std::stoi(fmaxQuantity);
    int quantity = std::stoi(fquantity);
    int sales = std::stoi(fsales);
    int purchaes = std::stoi(fpurchases);
    std::string descryption = fdescryption;

    database.Create();
    database.Insert(name, price, maxQuantity, quantity, sales, purchaes, descryption);
    database.Close();

    FillList();
}