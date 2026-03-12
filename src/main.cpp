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
#include "APIClient.hpp"

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
    APIClient api;

    bool pricesEntered = false;
    int choice;

    while (true) {
        utils.showLine();
        cout << "Real-Time Stock Price Intelligence System\n";
        utils.showLine();
        cout << "1. Add Price Stream\n";
        cout << "2. Fetch Price From API\n";
        cout << "3. Show Max & Min Price\n";
        cout << "4. Show Median Price\n";
        cout << "5. Show Sliding Window Median\n";
        cout << "6. Show Moving Average\n";
        cout << "7. Show Volatility\n";
        cout << "8. Detect Anomaly\n";
        cout << "9. Order Book Simulation\n";
        cout << "10. Exit\n";
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
        else if (choice == 2) {
            string symbol;
            cout << "Enter stock symbol (AAPL, TSLA etc): ";
            cin >> symbol;
            cin.ignore();

            double price = api.fetchPrice(symbol);

            if (price > 0) {
                priceStream.addPrice(price);
                cout << "Fetched price: " << price << endl;
                pricesEntered = true;
            } else {
                cout << "Failed to fetch price\n";
            }
     }
        else if (choice >= 3 && choice <= 8 && !pricesEntered) {
            cout << "Please add prices first!\n";
        }
        else if (choice == 3) {
            maxMin.showMaxMin(priceStream.getPrices());
        }
        else if (choice == 4) {
            median.showMedian(priceStream.getPrices());
        }
        else if (choice == 5) {
            slidingMedian.showSlidingMedian(priceStream.getPrices(), 3);
        }
        else if (choice == 6) {
            movingAvg.showAverage(priceStream.getPrices());
        }
        else if (choice == 7) {
            volatility.showVolatility(priceStream.getPrices());
        }
        else if (choice == 8) {
            anomaly.detect(priceStream.getPrices());
        }
        else if (choice == 9) {
           orderBook.executeOrder(priceStream.getPrices());
        }
        else if (choice == 10) {
            cout << "Exiting Program...\n";
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
