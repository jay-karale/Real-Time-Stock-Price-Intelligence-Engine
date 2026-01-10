#include "OrderBook.hpp"
#include <iostream>

using namespace std;

void OrderBook::executeOrder(const vector<double>& prices) {

    if (prices.empty()) {
        cout << "No market price available. Add prices first.\n";
        return;
    }

    double marketPrice = prices.back();
    int choice, quantity;

    cout << "Order Book\n";
    cout << "1. Buy\n";
    cout << "2. Sell\n";
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter quantity: ";
    cin >> quantity;

    if (quantity <= 0) {
        cout << "Invalid quantity\n";
        return;
    }

    if (choice == 1) {
        cout << "BUY Order Executed\n";
    }
    else if (choice == 2) {
        cout << "SELL Order Executed\n";
    }
    else {
        cout << "Invalid order type\n";
        return;
    }

    cout << "Quantity: " << quantity << endl;
    cout << "Execution Price: " << marketPrice << endl;
}

