// order_book/OrderBook.cpp

#include "OrderBook.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

// Add a new order to the book
void OrderBook::addOrder(const Order& order)
{
    orders.push_back(order);

    cout << "Order added: " << order.orderID << " - " << order.symbol << " "
         << (order.isBuy ? "Buy" : "Sell") << " "
         << order.volume << " @ " << order.price << endl;
}

// Remove an order using its ID
void OrderBook::removeOrder(const string& orderID)
{
    auto it = remove_if(orders.begin(), orders.end(),
                        [&orderID](const Order& order) {
                            return order.orderID == orderID;
                        });

    if (it != orders.end())
    {
        orders.erase(it, orders.end());
        cout << "Order removed: " << orderID << endl;
    }
    else
    {
        cout << "Order not found: " << orderID << endl;
    }
}

// Print all current orders
void OrderBook::displayOrders() const
{
    cout << "Current Orders in the Order Book:" << endl;

    for (const auto& order : orders)
    {
        cout << "Order ID: " << order.orderID
             << ", Symbol: " << order.symbol
             << ", Price: " << order.price
             << ", Volume: " << order.volume
             << ", Type: " << (order.isBuy ? "Buy" : "Sell")
             << endl;
    }
}
