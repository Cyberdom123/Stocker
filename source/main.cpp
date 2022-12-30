#include <iostream>
#include "databaseManager.h"
#include "window.h"

int main(int argc, char* argv[]){
  databaseManager database;
  database.Create();
  database.Insert(1,"tranzystory jfet P (drogi)", 300, "fajny tranzystorek");
  database.Insert(2,"tranzystory jfet N (drogi)", 300, "mniej fajny tranzystorek!");
  database.Update(2,"tranzystory jfet N (tani)", 500);
  database.Search("tranzystory");
  database.Close();

  auto app = Gtk::Application::create("org.gtkmm.example");

  //Shows the window and returns when it is closed.
  return app->make_window_and_run<Window>(argc, argv);
}