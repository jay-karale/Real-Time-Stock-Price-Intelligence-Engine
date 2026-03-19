#ifndef VOLATILITY_TRACKER_HPP
#define VOLATILITY_TRACKER_HPP

#include <vector>

class VolatilityTracker {
public:
    void showVolatility(const std::vector<double>& prices) const;
};

#endif
