#pragma once
// order_book/Order.hpp

#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>

using namespace std;

// Structure to represent a basic order
struct Order {
    string orderID;  // Unique ID for this order
    string symbol;   // e.g., "AAPL"
    double price;    // Price at which to buy/sell
    int volume;      // Number of shares
    bool isBuy;      // true = buy, false = sell

    // Constructor
    Order(const string& orderID, const string& symbol, double price, int volume, bool isBuy) {
        this->orderID = orderID;
        this->symbol = symbol;
        this->price = price;
        this->volume = volume;
        this->isBuy = isBuy;
    }
};

#endif // ORDER_HPP
