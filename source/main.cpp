#include <iostream>
#include <vector>
#include "databaseManager.h"
#include "window.h"
#include "listElements.h"

#include <gtkmm/application.h>

using dataFrame = std::vector<std::vector<std::string>>;

int main(int argc, char* argv[]){
  std::vector<char *> lineArgs;
  databaseManager database;

  //database.Create();
  //database.Insert("Diode", 3.14, 200, 100, 0, 100,"nic");
  // //database.Update(1, "PMOS", 6.28, 400, 200, 10, 210, "elo");
  // dataFrame data = database.Search("tranzystory");
  //database.ReadAll();
  //database.Close();


  auto app = Gtk::Application::create("org.gtkmm.example");

  //Shows the window and returns when it is closed.
  return app->make_window_and_run<Window>(argc, argv);

}
