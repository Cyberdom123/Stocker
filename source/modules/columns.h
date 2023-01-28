#include <gtkmm.h>

#pragma once

 //Tree model columns:
class ModelColumns : public Gtk::TreeModel::ColumnRecord
{
    public:
    ModelColumns() {add(m_col_id); add(m_col_name); add(m_col_price); add(m_col_max_quantity);
                    add(m_col_quantity); add(m_col_sales); add(m_col_purchases); add(m_col_description);};

    Gtk::TreeModelColumn<unsigned int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    Gtk::TreeModelColumn<Glib::ustring> m_col_price;
    Gtk::TreeModelColumn<int> m_col_max_quantity;
    Gtk::TreeModelColumn<int> m_col_quantity;
    Gtk::TreeModelColumn<int> m_col_sales;
    Gtk::TreeModelColumn<int> m_col_purchases;
    Gtk::TreeModelColumn<Glib::ustring> m_col_description;
};