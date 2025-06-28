#pragma once
// market_data_feed/MarketDataSubscriber.hpp

#ifndef MARKETDATASUBSCRIBER_HPP
#define MARKETDATASUBSCRIBER_HPP

#include <vector>
#include "MarketDataProtocols.hpp" // for Quote and Trade structs

using namespace std;

// Abstract base class for any component that wants to receive market data updates
class MarketDataSubscriber {
public:
    // Called when new quotes are available
    virtual void onQuoteUpdate(const vector<Quote>& quotes) = 0;

    // Called when new trades are available
    virtual void onTradeUpdate(const vector<Trade>& trades) = 0;

    // Virtual destructor
    virtual ~MarketDataSubscriber() = default;
};

#endif // MARKETDATASUBSCRIBER_HPP
