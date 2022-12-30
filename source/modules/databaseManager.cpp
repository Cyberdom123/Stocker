#include "databaseManager.h"

int databaseManager::Callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

//Replace with qui element
int databaseManager::PrintInfo(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
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
            "QUANTITY       INT     NOT NULL,"\
            "DESCRYPTION    TEXT);";

    int rc = sqlite3_exec(fdb, sql, Callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    return fisOpen;
}

//inssert 
void databaseManager::Insert(int id, std::string name, int quantity, std::string descryption){
    char *zErrMsg = 0;

    std::string sql;

    sql = "INSERT INTO RESOURCES (ID, NAME, QUANTITY, DESCRYPTION) VALUES"\
    "(NULL,'"+name+"',"+ std::to_string(quantity)+",'"+descryption+"');";

    int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

void databaseManager::Update(int id, std::string name, int quantity, std::string descryption){
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

    if(quantity != 0){
        sql = "UPDATE RESOURCES set QUANTITY ="+std::to_string(quantity)+"  where ID="+std::to_string(id)+";";
        
        int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);    
        }   
    }

    if(descryption != ""){
        sql = "UPDATE RESOURCES set DESCRYPTION ='" +descryption+ "' where ID="+std::to_string(id)+";";

        int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }      
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

void databaseManager::Search(std::string text){
   char *zErrMsg = 0;
    std::string sql;

    sql = "SELECT * from RESOURCES where NAME like '%"+ text +"%';";
    
    int rc = sqlite3_exec(fdb, sql.c_str(), Callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
}

void databaseManager::Delete(int id){
    char *zErrMsg = 0;
    std::string sql;

    sql = "DELETE from RESOURCES where ID="+std::to_string(id)+"; ";

}

void databaseManager::Close(){
    //check if database is open then close db
    if(!fisOpen){ 
        sqlite3_close(fdb);
    }
}
