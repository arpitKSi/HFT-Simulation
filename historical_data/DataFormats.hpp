#pragma once

#ifndef DATAFORMATS_HPP
#define DATAFORMATS_HPP

#include <string>
#include <vector>

using namespace std;

// Structure to store a single market data point
struct MarketData {
    string timestamp; // e.g., "2023-01-01 09:15"
    string symbol;    // e.g., "AAPL"
    double price;     // last traded price
    int volume;       // volume traded

    // Default constructor
    MarketData() {
        timestamp = "";
        symbol = "";
        price = 0.0;
        volume = 0;
    }

    // Parameterized constructor
    MarketData(const string& timestamp, const string& symbol, double price, int volume) {
        this->timestamp = timestamp;
        this->symbol = symbol;
        this->price = price;
        this->volume = volume;
    }
};

// Structure to store a full historical OHLCV data entry
struct HistoricalDataEntry {
    string date;
    string symbol;
    double openPrice;
    double closePrice;
    double highPrice;
    double lowPrice;
    int volume;

    // Constructor to initialize everything
    HistoricalDataEntry(const string& date, const string& symbol,
                        double openPrice, double closePrice,
                        double highPrice, double lowPrice, int volume) {
        this->date = date;
        this->symbol = symbol;
        this->openPrice = openPrice;
        this->closePrice = closePrice;
        this->highPrice = highPrice;
        this->lowPrice = lowPrice;
        this->volume = volume;
    }
};

// just a typedef for vector of full OHLCV entries
using HistoricalData = vector<HistoricalDataEntry>;

#endif // DATAFORMATS_HPP
