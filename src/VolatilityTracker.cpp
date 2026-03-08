#include "VolatilityTracker.hpp"
#include <iostream>
#include <cmath>
using namespace std;

void VolatilityTracker::showVolatility(const vector<double>& prices) const {
    if (prices.size() < 2) {
        cout << "Not enough data\n";
        return;
    }

    double mean = 0;
    for (double p : prices) mean += p;
    mean /= prices.size();

    double var = 0;
    for (double p : prices)
        var += (p - mean) * (p - mean);

    cout << "Volatility: " << sqrt(var / prices.size()) << endl;
}
