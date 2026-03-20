#include "OrderBook.hpp"

ExecutionResult OrderBook::executeOrder(
    const Order& order,
    const std::vector<double>& prices
) {
    ExecutionResult result{false, 0.0, 0, ""};

    if (prices.empty()) {
        result.message = "Market price unavailable.";
        return result;
    }

    if (!validateOrder(order)) {
        result.message = "Invalid order parameters.";
        return result;
    }

    double marketPrice = prices.back();

    if (!validateMarketPrice(marketPrice)) {
        result.message = "Invalid market price.";
        return result;
    }

    result.success = true;
    result.executionPrice = marketPrice;
    result.quantity = order.quantity;

    result.message =
        (order.type == OrderType::BUY)
        ? "BUY order executed."
        : "SELL order executed.";

    return result;
}

bool OrderBook::validateOrder(const Order& order) const {
    return order.quantity > 0;
}

bool OrderBook::validateMarketPrice(double price) const {
    return price > 0.0;
}