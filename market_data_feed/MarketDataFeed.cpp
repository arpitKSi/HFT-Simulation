#pragma once
// src/market_data_feed/MarketDataFeed.cpp

#include "MarketDataFeed.hpp"
#include "MarketDataProtocols.hpp"
#include "MarketDataSubscriber.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <stdexcept>

using namespace std;

// Constructor: setup parser and mark not running
MarketDataFeed::MarketDataFeed(MarketDataProtocol protocol)
{
    running = false;
    parser = createParser(protocol);

    if (!parser)
    {
        throw runtime_error("Failed to create a market data parser!");
    }
}

// Destructor: clean up memory
MarketDataFeed::~MarketDataFeed()
{
    delete parser;
}

// This function can be used to connect to some source
void MarketDataFeed::initialize(const string& connection_string)
{
    cout << "Initializing connection with: " << connection_string << endl;
}

// Start processing the data feed in a thread
void MarketDataFeed::start()
{
    if (!parser)
    {
        cerr << "Parser not initialized. Cannot start feed." << endl;
        return;
    }

    cout << "Starting market data feed..." << endl;
    running = true;

    // launch background thread
    feedThread = thread(&MarketDataFeed::processDataFeed, this);
}

// Stop the feed and wait for thread to join
void MarketDataFeed::stop()
{
    running = false;

    if (feedThread.joinable())
    {
        feedThread.join();
    }

    cout << "Market data feed stopped." << endl;
}

// The background thread function
void MarketDataFeed::processDataFeed()
{
    while (running)
    {
        // simulate receiving a message
        string message = simulateIncomingMessage();

        // try parsing it
        if (!parser->parseMessage(message))
        {
            cerr << "Failed to parse message: " << message << endl;
            continue;
        }

        // get quotes and trades
        vector<Quote> quotes = parser->getQuotes();
        vector<Trade> trades = parser->getTrades();

        // send them to everyone who's subscribed
        notifySubscribers(quotes, trades);

        // simulate delay
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

// Add someone to the subscriber list
void MarketDataFeed::subscribe(MarketDataSubscriber* subscriber)
{
    subscribers.push_back(subscriber);
}

// Tell all subscribers about new quotes and trades
void MarketDataFeed::notifySubscribers(const vector<Quote>& quotes, const vector<Trade>& trades)
{
    for (auto* subscriber : subscribers)
    {
        subscriber->onQuoteUpdate(quotes);
        subscriber->onTradeUpdate(trades);
    }
}

// Fake message for testing
string MarketDataFeed::simulateIncomingMessage() const
{
    return "FIX message: Sample trade data";
}
