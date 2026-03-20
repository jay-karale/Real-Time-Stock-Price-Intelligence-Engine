#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <thread>
#include <chrono>

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
    unique_ptr<MovingAverage> movingAvg = nullptr;
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
                if (movingAvg)
                    movingAvg->update(p);
            }

            pricesEntered = true;
            cout << "Prices added successfully\n";
        }

        else if (choice == 2) {

            string symbol;
            int count;

            cout << "Enter stock symbol: ";
            cin >> symbol;

            cout << "Enter number of prices to fetch: ";
            cin >> count;
            cin.ignore();

            cout << "\nFetching prices...\n";

            for (int i = 0; i < count; i++) {

                double price = api.fetchPrice(symbol);

                if (price > 0) {
                    priceStream.addPrice(price);

                    if (movingAvg)
                        movingAvg->update(price);

                    cout << i + 1 << " -> " << price << " added\n";
                    pricesEntered = true;
                } else {
                    cout << "Fetch failed\n";
                }

                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
        }

        else if (choice >= 3 && choice <= 9 && !pricesEntered) {
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

            const auto& prices = priceStream.getPrices();

            if (prices.empty()) {
                cout << "Please add prices first!\n";
                continue;
            }

            if (!movingAvg) {

                size_t window;
                cout << "Enter Moving Average window size: ";
                cin >> window;
                cin.ignore();

                movingAvg = make_unique<MovingAverage>(window);

                for (double p : prices)
                    movingAvg->update(p);
            }

            auto avg = movingAvg->getAverage();

            if (avg)
                cout << "Moving Average: " << *avg << endl;
            else
                cout << "Not enough data\n";
        }

        else if (choice == 7) {
            volatility.showVolatility(priceStream.getPrices());
        }

        else if (choice == 8) {
            anomaly.detect(priceStream.getPrices());
        }

        else if (choice == 9) {

            int type, qty;

            cout << "1. Buy\n2. Sell\n";
            cout << "Enter order type: ";
            cin >> type;

            cout << "Enter quantity: ";
            cin >> qty;
            cin.ignore();

            Order order;
            order.type = (type == 1) ? OrderType::BUY : OrderType::SELL;
            order.quantity = qty;

            ExecutionResult res =
                orderBook.executeOrder(order, priceStream.getPrices());

            cout << res.message << endl;

            if (res.success) {
                cout << "Quantity: " << res.quantity << endl;
                cout << "Execution Price: " << res.executionPrice << endl;
            }
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
