#include "databaseManager.h"

int databaseManager::Callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int databaseManager::PrintInfo(void *p_data, int num_fields, char **p_fields, char **p_col_names){
    dataFrame* resourcesPtr = static_cast<dataFrame*>(p_data);
    resourcesPtr->emplace_back(p_fields, p_fields + num_fields);
    return 0;
}

int databaseManager::Create(){
    char *zErrMsg = 0;

    //open an SQLite database or create if not exist.
    fisOpen = sqlite3_open("stockerDatabase.db", &fdb);

    const char *sql;

    //check if the table has been created, if not create it
    sql = "CREATE TABLE IF NOT EXISTS RESOURCES("  \
            "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
            "NAME   TEXT(40)    NOT NULL UNIQUE," \
            "PRICE   FLOAT    NOT NULL," \
            "MAX_QUANTITY       INT     NOT NULL,"\
            "QUANTITY       INT     NOT NULL,"\
            "SALES       INT,"\
            "PURCHASES       INT     NOT NULL,"\
            "DESCRIPTION    TEXT);";

    int rc = sqlite3_exec(fdb, sql, Callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    return fisOpen;
}

//inssert 
void databaseManager::Insert(std::string name, float price, int maxQuantity, int quantity,
                             int sales, int purchases, std::string description){
    char *zErrMsg = 0;

    std::string sql;

    sql = "INSERT INTO RESOURCES (ID, NAME, PRICE, MAX_QUANTITY, QUANTITY,"\
          "SALES, PURCHASES, DESCRIPTION) VALUES"\
          "(NULL,'"+name+"',"+ std::to_string(price)+","+\
          std::to_string(maxQuantity)+","+\
          std::to_string(quantity)+","+std::to_string(sales)+\
          ","+std::to_string(purchases)+",'"+description+"');";

    int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

void databaseManager::Update(int id, std::string name, float price, int maxQuantity, int quantity,
                             int sales, int purchases, std::string description){
    char *zErrMsg = 0;
    
    std::string sql;

    if(name != ""){
        sql = "UPDATE RESOURCES set NAME ='" +name+ "' where ID="+std::to_string(id)+";";

        int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    if(price != 0){
        sql = "UPDATE RESOURCES set PRICE ="+std::to_string(price)+" where ID="+std::to_string(id)+";";

        int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    if(maxQuantity != 0){
        sql = "UPDATE RESOURCES set MAX_QUANTITY ="+std::to_string(maxQuantity)+" where ID="+std::to_string(id)+";";

        int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    if(quantity != -1){
        sql = "UPDATE RESOURCES set QUANTITY ="+std::to_string(quantity)+"  where ID="+std::to_string(id)+";";
        
        int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);    
        }   
    }

    if(sales != -1){
        sql = "UPDATE RESOURCES set SALES ="+std::to_string(sales)+"  where ID="+std::to_string(id)+";";
        
        int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);    
        }   
    }

    if(purchases != -1){
        sql = "UPDATE RESOURCES set PURCHASES ="+std::to_string(purchases)+"  where ID="+std::to_string(id)+";";
        
        int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);    
        }   
    }


    sql = "UPDATE RESOURCES set DESCRIPTION ='" +description+ "' where ID="+std::to_string(id)+";";

    int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }      

}


void databaseManager::ReadAll(){
    char *zErrMsg = 0;
    std::string sql;

    sql = "SELECT * from RESOURCES";

    int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

void databaseManager::Read(int id){
    char *zErrMsg = 0;
    std::string sql;

    sql = "SELECT * from RESOURCES where ID="+std::to_string(id)+";";

    int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
}

std::vector<std::vector<std::string>> databaseManager::Search(std::string text){
    char *zErrMsg = 0;
    std::string sql;

    dataFrame resources;

    sql = "SELECT * from RESOURCES where NAME like '%"+ text +"%';";
    
    int rc = sqlite3_exec(fdb, sql.c_str(), PrintInfo, &resources, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    return resources;

}

void databaseManager::Delete(int id){
    char *zErrMsg = 0;
    std::string sql;

    sql = "DELETE from RESOURCES where ID="+std::to_string(id)+"; ";

    int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
}

void databaseManager::Close(){
    //check if database is open then close db
    if(!fisOpen){ 
        sqlite3_close(fdb);
    }
}
