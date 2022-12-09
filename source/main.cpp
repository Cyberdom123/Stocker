#include <iostream>
#include "databaseManager.h"


int main(){
  databaseManager database;
  database.Create();
  database.Insert(2,"tranzystory jfet N (drogi)", 300);
  database.Close();
}