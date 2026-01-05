#include "PriceStream.hpp"

void PriceStream::addPrice(double p) {
    prices.push_back(p);
}

std::vector<double> PriceStream::getPrices() const {
    return prices;
}
