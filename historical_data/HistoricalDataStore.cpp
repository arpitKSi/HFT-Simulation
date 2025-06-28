// historical_data/HistoricalDataStore.cpp

#include "HistoricalDataStore.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Load historical data from a CSV file
bool HistoricalDataStore::loadFromCSV(const string& filePath)
{
    ifstream file(filePath);
    
    if (!file.is_open())
    {
        cerr << "Could not open the file: " << filePath << endl;
        return false;
    }

    string line;

    // Skip the first line (header)
    getline(file, line);

    // Read each line and parse it into a HistoricalDataEntry
    while (getline(file, line))
    {
        HistoricalDataEntry entry = parseCSVLine(line);
        dataStore[entry.symbol].push_back(entry); // Group by symbol
    }

    file.close();

    cout << "Loaded historical data from " << filePath << endl;
    return true;
}

// Get all historical data for a specific symbol
HistoricalData HistoricalDataStore::getHistoricalData(const string& symbol) const
{
    auto it = dataStore.find(symbol);
    if (it != dataStore.end())
    {
        return it->second;
    }

    return {}; // return empty vector if not found
}

// Helper function to convert a line of CSV into a HistoricalDataEntry
HistoricalDataEntry HistoricalDataStore::parseCSVLine(const string& line)
{
    stringstream ss(line);
    string date, symbol;
    double openPrice, closePrice, highPrice, lowPrice;
    int volume;

    getline(ss, date, ',');
    getline(ss, symbol, ',');
    ss >> openPrice;
    ss.ignore(1, ',');
    ss >> closePrice;
    ss.ignore(1, ',');
    ss >> highPrice;
    ss.ignore(1, ',');
    ss >> lowPrice;
    ss.ignore(1, ',');
    ss >> volume;

    return HistoricalDataEntry(date, symbol, openPrice, closePrice, highPrice, lowPrice, volume);
}
