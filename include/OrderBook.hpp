#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include <vector>
#include <string>

enum class OrderType {
    BUY,
    SELL
};

struct Order {
    OrderType type;
    int quantity;
};

struct ExecutionResult {
    bool success;
    double executionPrice;
    int quantity;
    std::string message;
};

class OrderBook {
public:
    ExecutionResult executeOrder(
        const Order& order,
        const std::vector<double>& prices
    );

private:
    bool validateOrder(const Order& order) const;
    bool validateMarketPrice(double price) const;
};

#endif