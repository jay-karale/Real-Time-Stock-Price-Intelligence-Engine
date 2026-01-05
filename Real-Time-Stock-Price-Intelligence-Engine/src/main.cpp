#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "PriceStream.hpp"
#include "MaxMinTracker.hpp"
#include "MedianTracker.hpp"
#include "SlidingWindowMedian.hpp"
#include "MovingAverage.hpp"
#include "VolatilityTracker.hpp"
#include "AnomalyDetector.hpp"
#include "OrderBook.hpp"
#include "Utils.hpp"

int main() {

    PriceStream priceStream;
    MaxMinTracker maxMin;
    MedianTracker median;
    SlidingWindowMedian slidingMedian;
    MovingAverage movingAvg;
    VolatilityTracker volatility;
    AnomalyDetector anomaly;
    OrderBook orderBook;
    Utils utils;

    bool pricesEntered = false;
    int choice;

    while (true) {
        utils.showLine();
        cout << "Real-Time Stock Price Intelligence System\n";
        utils.showLine();
        cout << "1. Add Price Stream\n";
        cout << "2. Show Max & Min Price\n";
        cout << "3. Show Median Price\n";
        cout << "4. Show Sliding Window Median\n";
        cout << "5. Show Moving Average\n";
        cout << "6. Show Volatility\n";
        cout << "7. Detect Anomaly\n";
        cout << "8. Order Book Simulation\n";
        cout << "9. Exit\n";
        utils.showLine();
        cout << "Enter your choice: ";

        string line;
        getline(cin, line);
        stringstream ss(line);

        if (!(ss >> choice)) {
            cout << "Invalid input\n";
            continue;
        }

        if (choice == 1) {
            cout << "Enter prices (space separated): ";
            getline(cin, line);
            stringstream ss2(line);

            double p;
            while (ss2 >> p) {
                priceStream.addPrice(p);
            }
            pricesEntered = true;
            cout << "Prices added successfully\n";
        }
        else if (choice >= 2 && choice <= 7 && !pricesEntered) {
            cout << "Please add prices first!\n";
        }
        else if (choice == 2) {
            maxMin.showMaxMin(priceStream.getPrices());
        }
        else if (choice == 3) {
            median.showMedian(priceStream.getPrices());
        }
        else if (choice == 4) {
            slidingMedian.showSlidingMedian(priceStream.getPrices(), 3);
        }
        else if (choice == 5) {
            movingAvg.showAverage(priceStream.getPrices());
        }
        else if (choice == 6) {
            volatility.showVolatility(priceStream.getPrices());
        }
        else if (choice == 7) {
            anomaly.detect(priceStream.getPrices());
        }
        else if (choice == 8) {
            orderBook.simulate();
        }
        else if (choice == 9) {
            cout << "Exiting Program...\n";
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
