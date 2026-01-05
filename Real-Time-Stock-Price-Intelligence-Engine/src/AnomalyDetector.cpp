#include "AnomalyDetector.hpp"
#include <iostream>
#include <cmath>  

using namespace std;

void AnomalyDetector::detect(const vector<double>& prices) const {
    if (prices.size() < 2) {
        cout << "Not enough data for anomaly detection\n";
        return;
    }

    double change = prices.back() - prices[prices.size() - 2];

    if (std::fabs(change) > 20) {
        cout << "Anomaly Detected!\n";
    } else {
        cout << "No Anomaly Detected\n";
    }
}

