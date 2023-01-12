#include <gtkmm.h>
#include "columns.h"
#include "databaseManager.h"

#pragma once

class listElements{
    public:
        listElements();
        virtual ~listElements();
        //void FillColumns(dataFrame& data, databaseManager& manager);
        Glib::RefPtr<Gtk::ListStore> GetListElements() const;
        void AddElement(std::string fname, std::string fprice,
                    std::string fmaxQuantity, std::string fquantity, std::string fsales, 
                    std::string fpurchases, std::string fdescryption);

        void UpdateElement(int fid, std::string fname, std::string fprice,
                    std::string fmaxQuantity, std::string fquantity, std::string fsales, 
                    std::string fpurchases, std::string fdescryption);

        void FillList(std::string text="");
    private:
        ModelColumns m_Columns;
        databaseManager database;
        Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
};