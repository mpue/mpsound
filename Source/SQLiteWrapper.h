/*
  ==============================================================================

    SQLiteWrapper.h
    Created: 10 Jan 2019 2:45:26pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <sqlite3.h>
#include <map>

class SQLiteWrapper {
  
public:
    SQLiteWrapper();
    virtual ~SQLiteWrapper();
    
    bool openDatabase(String name);
    bool close();
    bool query(String query);
    bool createDatabase();
    bool updateDB(String rootDir);
    static std::map<String,String> results;
private:
    sqlite3 *db;

};
