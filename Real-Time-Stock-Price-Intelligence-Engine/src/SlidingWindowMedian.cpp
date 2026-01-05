#include "SlidingWindowMedian.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

void SlidingWindowMedian::showSlidingMedian(const vector<double>& prices, int k) const {
    if (prices.size() < k) {
        cout << "Not enough data\n";
        return;
    }

    vector<double> window(prices.end() - k, prices.end());
    sort(window.begin(), window.end());

    if (k % 2 == 0)
        cout << "Sliding Median: " << (window[k/2 - 1] + window[k/2]) / 2 << endl;
    else
        cout << "Sliding Median: " << window[k/2] << endl;
}
