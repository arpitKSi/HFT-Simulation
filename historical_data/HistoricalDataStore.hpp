#pragma once

#ifndef HISTORICALDATASTORE_HPP
#define HISTORICALDATASTORE_HPP

#include "DataFormats.hpp"
#include <string>
#include <unordered_map>

using namespace std;

// Class to store and load historical OHLCV data from CSV
class HistoricalDataStore {
public:
    HistoricalDataStore() = default;
    ~HistoricalDataStore() = default;

    // Load data from CSV file
    bool loadFromCSV(const string& filePath);

    // Get data for a specific symbol like "AAPL"
    HistoricalData getHistoricalData(const string& symbol) const;

private:
    // Stores all data grouped by symbol
    unordered_map<string, HistoricalData> dataStore;

    // Parses a line from CSV into HistoricalDataEntry
    HistoricalDataEntry parseCSVLine(const string& line);
};

#endif // HISTORICALDATASTORE_HPP
