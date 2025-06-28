#pragma once
// market_data_feed/MarketDataFeed.hpp

#ifndef MARKETDATAFEED_HPP
#define MARKETDATAFEED_HPP

#include <string>
#include <vector>
#include <thread>
#include "MarketDataProtocols.hpp"

using namespace std;

// Forward declarations
class MarketDataParser;
class MarketDataSubscriber;

// Main class for handling market data feed
class MarketDataFeed {
public:
    // Constructor and destructor
    MarketDataFeed(MarketDataProtocol protocol);
    ~MarketDataFeed();

    // Main public methods
    void initialize(const string& connection_string);
    void start();
    void stop();
    void subscribe(MarketDataSubscriber* subscriber);

private:
    // Internal thread method
    void processDataFeed();

    // Notify all subscribers
    void notifySubscribers(const vector<Quote>& quotes, const vector<Trade>& trades);

    // Simulated incoming message (for testing)
    string simulateIncomingMessage() const;

    // Members
    bool running;                                // true if feed is active
    MarketDataParser* parser;                    // parses incoming messages
    thread feedThread;                           // background thread
    vector<MarketDataSubscriber*> subscribers;   // list of subscribers
};

#endif // MARKETDATAFEED_HPP
