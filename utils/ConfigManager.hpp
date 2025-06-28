#pragma once

// utils/ConfigManager.hpp

#ifndef CONFIGMANAGER_HPP
#define CONFIGMANAGER_HPP

#include <string>
#include <unordered_map>

using namespace std;

/// Simple config manager to load key-value settings from a file
class ConfigManager {
public:
    // Load config from file
    bool loadConfig(const string& filename);

    // Get value for a given key
    string getValue(const string& key) const;

private:
    unordered_map<string, string> configData;  // Stores config key-value pairs
};

#endif // CONFIGMANAGER_HPP
