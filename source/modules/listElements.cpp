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
        row[m_Columns.m_col_price] = a[2];
        row[m_Columns.m_col_max_quantity] = std::stoi(a[3]);
        row[m_Columns.m_col_quantity] = std::stoi(a[4]);
        row[m_Columns.m_col_sales] = std::stoi(a[5]);
        row[m_Columns.m_col_purchases] = std::stoi(a[6]);
        row[m_Columns.m_col_description] = a[7];
    }
}

bool listElements::AddElement(std::string fname, std::string fprice,
                    std::string fmaxQuantity, std::string fsales,
                    std::string fpurchases, std::string fdescription)
{
    try{
        std::string name = fname;
        float price = std::stof(fprice);
        int maxQuantity = std::stoi(fmaxQuantity);
        int sales = std::stoi(fsales);
        int purchaes = std::stoi(fpurchases);
        int quantity = purchaes - sales;
        std::string description = fdescription;

        if((quantity) >= 0 && (quantity <= maxQuantity)){
            database.Create();
            database.Insert(name, price, maxQuantity, quantity, sales, purchaes, description);
            database.Close();
        }else{
            return false;
        }
        return true;
    }catch(...){
        return false;
    }

}

bool listElements::UpdateElement(int fid, std::string fname, std::string fprice,
                    std::string fmaxQuantity, std::string fsales, 
                    std::string fpurchases, std::string fdescription)
{
    try{
        int sales = std::stoi(fsales);
        int purchaes = std::stoi(fpurchases);
        int id = fid;
        std::string name = fname;
        float price = std::stof(fprice);
        int maxQuantity = std::stoi(fmaxQuantity);
        int quantity = purchaes - sales; //throw exception if sales < purchases
        std::string description = fdescription;

        if((quantity) >= 0 && (quantity <= maxQuantity)){
            database.Create();
            database.Update(id, name, price, maxQuantity, quantity, sales, purchaes, description);
            database.Close();
        }else{
            return false;
        }
        return true;
    }catch(...){
        return false;
    }
}

void listElements::DeleteElement(int fid){
    database.Create();
    database.Delete(fid);
    database.Close();
}