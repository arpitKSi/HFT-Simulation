#pragma once
// market_data_feed/MarketDataProtocols.hpp

#ifndef MARKETDATAPROTOCOLS_HPP
#define MARKETDATAPROTOCOLS_HPP

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Supported protocols for market data
enum class MarketDataProtocol {
    FIX,    // Financial Information Exchange
    ITCH,   // ITCH Protocol
    CUSTOM  // Custom (not yet implemented)
};

// Simple quote structure
struct Quote {
    string symbol;
    double price;
    int volume;

    Quote(const string& symbol, double price, int volume) {
        this->symbol = symbol;
        this->price = price;
        this->volume = volume;
    }
};

// Simple trade structure
struct Trade {
    string symbol;
    double price;
    int volume;
    // string tradeID; // You can use this if needed

    Trade(const string& symbol, double price, int volume, const string& tradeID) {
        this->symbol = symbol;
        this->price = price;
        this->volume = volume;
        // tradeID is not stored, but can be used
    }
};

// Abstract base class for market data parsers
class MarketDataParser {
public:
    virtual ~MarketDataParser() = default;

    virtual bool parseMessage(const string& message) = 0;
    virtual vector<Quote> getQuotes() const = 0;
    virtual vector<Trade> getTrades() const = 0;
};

// FIX protocol parser
class FIXParser : public MarketDataParser {
public:
    bool parseMessage(const string& message) override {
        cout << "Parsing FIX message: " << message << endl;
        return true;
    }

    vector<Quote> getQuotes() const override {
        return { Quote("AAPL", 150.5, 20), Quote("GOOGL", 2800.0, 15) };
    }

    vector<Trade> getTrades() const override {
        return { Trade("AAPL", 150.5, 20, "TRD123"), Trade("GOOGL", 2800.0, 5, "TRD456") };
    }
};

// ITCH protocol parser
class ITCHParser : public MarketDataParser {
public:
    bool parseMessage(const string& message) override {
        cout << "Parsing ITCH message: " << message << endl;
        return true;
    }

    vector<Quote> getQuotes() const override {
        return { Quote("MSFT", 300.25, 20), Quote("NFLX", 600.0, 20) };
    }

    vector<Trade> getTrades() const override {
        return { Trade("AAPL", 300.5, 20, "TRD123"), Trade("GOOGL", 2800.0, 5, "TRD456") };
    }
};

// Factory to create parser based on protocol
inline MarketDataParser* createParser(MarketDataProtocol protocol)
{
    switch (protocol)
    {
    case MarketDataProtocol::FIX:
        return new FIXParser();

    case MarketDataProtocol::ITCH:
        return new ITCHParser();

    // case MarketDataProtocol::CUSTOM:
    //     return new CustomParser(); // implement later

    default:
        cerr << "Unsupported protocol!" << endl;
        return nullptr;
    }
}

#endif // MARKETDATAPROTOCOLS_HPP
