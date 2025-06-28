// utils/ConfigManager.cpp

#include "ConfigManager.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Load configuration from file into map
bool ConfigManager::loadConfig(const string& filename) {
    ifstream configFile(filename);
    if (!configFile.is_open()) {
        cerr << "Could not open config file: " << filename << endl;
        return false;
    }

    string line;
    while (getline(configFile, line)) {
        istringstream iss(line);
        string key, value;

        if (getline(iss, key, '=') && getline(iss, value)) {
            configData[key] = value;
        }
    }

    configFile.close();
    return true;
}

// Get value from config using key
string ConfigManager::getValue(const string& key) const {
    auto it = configData.find(key);
    if (it != configData.end()) {
        return it->second;
    }
    return "";
}
