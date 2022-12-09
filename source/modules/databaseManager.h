//Singleton for one instance of Manager
#include <stdlib.h>
#include <sqlite3.h> 
#include <string>
#include <iostream> //delete it if you end with debuging

#pragma once

class databaseManager{
    private:
        sqlite3 *fdb;
        int fisOpen{0};    
        static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    public:
        int Create(); 
        void Insert(int id, std::string name, int quantity);
        void Update();
        void Read(); 
        void Delete();
        void Close();
}; 