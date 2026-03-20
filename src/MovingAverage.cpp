#include "MovingAverage.hpp"
#include <stdexcept>

MovingAverage::MovingAverage(size_t windowSize)
    : window(windowSize), runningSum(0.0)
{
    if (windowSize == 0)
        throw std::invalid_argument("Window size must be greater than 0");
}

void MovingAverage::update(double price) {
    buffer.push(price);
    runningSum += price;

    if (buffer.size() > window) {
        runningSum -= buffer.front();
        buffer.pop();
    }
}

std::optional<double> MovingAverage::getAverage() const {
    if (buffer.empty())
        return std::nullopt;

    return runningSum / buffer.size();
}