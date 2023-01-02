//Singleton for one instance of Manager
#include <stdlib.h>
#include <sqlite3.h> 
#include <string>
#include <vector>
#include <iostream>

#pragma once

using dataFrame = std::vector<std::vector<std::string>>;

class databaseManager{
    private:
        sqlite3 *fdb;
        int fisOpen{0};
        static int Callback(void *NotUsed, int argc, char **argv, char **azColName);
        static int PrintInfo(void *data, int argc, char **argv, char **azColName);
    public:
        int Create(); 
        void Insert(int id, std::string name, int quantity, std::string descryption="");
        void Update(int id, std::string name = "", int quantity = 0, std::string descryption = "");
        void ReadAll();
        void Read(int id);
        dataFrame Search(std::string text);
        void Delete(int id);
        void Close();
}; 

//To do:
//- replace void with string, in ordert to take error message with gui element
//- Pass function as argument in print info method