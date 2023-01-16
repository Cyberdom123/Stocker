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
        bool AddElement(std::string fname, std::string fprice,
                    std::string fmaxQuantity, std::string fsales, 
                    std::string fpurchases, std::string fdescryption);

        bool UpdateElement(int fid, std::string fname, std::string fprice,
                    std::string fmaxQuantity, std::string fsales, 
                    std::string fpurchases, std::string fdescryption);

        void FillList(std::string text="");

        void DeleteElement(int fid);
    private:
        ModelColumns m_Columns;
        databaseManager database;
        Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
};