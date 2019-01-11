/*
  ==============================================================================

    SQLiteWrapper.cpp
    Created: 10 Jan 2019 2:45:26pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "SQLiteWrapper.h"
#include <iostream>

SQLiteWrapper::SQLiteWrapper() {

}

SQLiteWrapper::~SQLiteWrapper() {
    
}

std::map<String,String> SQLiteWrapper::results = std::map<String,String>();

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    for(int i = 0;i < argc / 2; i+=2){
        std::cout << azColName[i] << " " << argv[i] << std::endl;
        SQLiteWrapper::results[argv[i]] = argv[i+1];
    }
    return 0;
}

bool SQLiteWrapper::openDatabase(String name) {
    int rc = sqlite3_open(name.toUTF8(), &db);
    if (rc) {
        sqlite3_close(db);
        return false;
    }
    return true;
}

bool SQLiteWrapper::close() {
    sqlite3_close(db);
    return true;
}

bool SQLiteWrapper::query(String query) {
    
    char* errorMsg;
    
    int rc = sqlite3_exec(db, query.toUTF8(), callback, 0, &errorMsg);
    
    if (rc != SQLITE_OK) {
        Logger::getCurrentLogger()->writeToLog(String(errorMsg));
        sqlite3_free(errorMsg);
        return false;
    }
    return true;
}

bool SQLiteWrapper::createDatabase() {
    String statement = "create table if not exists files (name varchar(255), path varchar(255))";
    
    if (!openDatabase("Files")) {
        Logger::getCurrentLogger()->writeToLog("Could not create database.");
        return false;
    }
    else {
        query(statement);
    }
    
    return true;
}


bool SQLiteWrapper::updateDB() {
    
    String userHome = File::getSpecialLocation(File::userHomeDirectory).getFullPathName();
    
    
    File root = File(userHome+"/Documents/samples");
    
    Array<File> files = root.findChildFiles(File::TypesOfFileToFind::findFiles,true, "*.wav;*.aiff;*.mp3");
    
    for(int i = 0; i < files.size();i++) {
        String queryString = "insert into files values(\""+files.getReference(i).getFileName()+"\",\"" + files.getReference(i).getFullPathName()+"\")";
        query(queryString);
    }
    
    return true;
    
}
