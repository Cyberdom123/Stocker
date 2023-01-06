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

        void FillList();
    private:
        ModelColumns m_Columns;
        databaseManager database;
        Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
};