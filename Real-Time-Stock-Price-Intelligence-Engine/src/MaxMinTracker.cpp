#include "MaxMinTracker.hpp"
#include <iostream>
using namespace std;

void MaxMinTracker::showMaxMin(const vector<double>& prices) const {
    if (prices.empty()) {
        cout << "No prices available\n";
        return;
    }

    double mx = prices[0], mn = prices[0];
    for (double p : prices) {
        if (p > mx) mx = p;
        if (p < mn) mn = p;
    }

    cout << "Max Price: " << mx << "\nMin Price: " << mn << endl;
}
