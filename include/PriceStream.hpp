#ifndef PRICE_STREAM_HPP
#define PRICE_STREAM_HPP

#include <vector>

class PriceStream {
public:
    void addPrice(double p);
    std::vector<double> getPrices() const;

private:
    std::vector<double> prices;
};

#endif
