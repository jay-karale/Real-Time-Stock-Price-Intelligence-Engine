#include "MovingAverage.hpp"
#include <iostream>
using namespace std;

void MovingAverage::showAverage(const vector<double>& prices) const {
    if (prices.empty()) {
        cout << "No prices available\n";
        return;
    }

    double sum = 0;
    for (double p : prices) sum += p;

    cout << "Moving Average: " << sum / prices.size() << endl;
}
