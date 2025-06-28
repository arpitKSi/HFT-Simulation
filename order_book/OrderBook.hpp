#pragma once
// order_book/OrderBook.hpp

#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include <vector>
#include <string>
#include "Order.hpp"

using namespace std;

// Class to manage all buy/sell orders
class OrderBook {
public:
    // Add a new order to the book
    void addOrder(const Order& order);

    // Remove an order by ID
    void removeOrder(const string& orderID);

    // Print all orders in the book
    void displayOrders() const;

private:
    vector<Order> orders; // Stores all current orders
};

#endif // ORDERBOOK_HPP
