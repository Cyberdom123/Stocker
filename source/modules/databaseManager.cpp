#include "databaseManager.h"

//read about it
int databaseManager::callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
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
            "ID INT PRIMARY KEY     NOT NULL," \
            "NAME           TEXT    NOT NULL," \
            "QUANTITY            INT     NOT NULL );";

    int rc = sqlite3_exec(fdb, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    return fisOpen;
}

    //inssert 
    void databaseManager::Insert(int id, std::string name, int quantity){
    char *zErrMsg = 0;

    std::string sql;

    sql = "INSERT INTO RESOURCES (ID, NAME, QUANTITY) VALUES ("+std::to_string(id)+",'"+name+"',"+ std::to_string(quantity)+");";

    //sql = "INSERT INTO RESOURCES (ID,NAME,QUANTITY) VALUES (1, 'Paul', 32);";

    int rc = sqlite3_exec(fdb, sql.c_str(), callback, 0, &zErrMsg);

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