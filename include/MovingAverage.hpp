#ifndef MOVINGAVERAGE_HPP
#define MOVINGAVERAGE_HPP

#include <queue>
#include <optional>
#include <cstddef>

class MovingAverage {
public:
    explicit MovingAverage(size_t windowSize);

    void update(double price);
    std::optional<double> getAverage() const;

private:
    size_t window;
    std::queue<double> buffer;
    double runningSum;
};

#endif