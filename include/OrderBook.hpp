#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include <vector>

class OrderBook {
public:
    void executeOrder(const std::vector<double>& prices);
};

#endif

