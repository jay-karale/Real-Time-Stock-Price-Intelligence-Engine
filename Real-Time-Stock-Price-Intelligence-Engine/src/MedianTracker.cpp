#include "MedianTracker.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

void MedianTracker::showMedian(const vector<double>& prices) const {
    if (prices.empty()) {
        cout << "No prices available\n";
        return;
    }

    vector<double> temp = prices;
    sort(temp.begin(), temp.end());

    int n = temp.size();
    if (n % 2 == 0)
        cout << "Median: " << (temp[n/2 - 1] + temp[n/2]) / 2 << endl;
    else
        cout << "Median: " << temp[n/2] << endl;
}
