#include "MaxMinTracker.hpp"
#include <iostream>
#include <queue>
using namespace std;

void MaxMinTracker::showMaxMin(const vector<double>& prices) const {
    if (prices.empty()) {
        cout << "No prices available\n";
        return;
    }

    priority_queue<double> maxHeap(prices.begin(), prices.end());
    priority_queue<double, vector<double>, greater<double>> minHeap(prices.begin(), prices.end());

    cout << "Max Price: " << maxHeap.top() << "\nMin Price: " << minHeap.top() << endl;
}
