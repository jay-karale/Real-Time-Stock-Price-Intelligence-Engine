#ifndef APICLIENT_HPP
#define APICLIENT_HPP

#pragma once
#include <string>

class APIClient
{
public:
    double fetchPrice(const std::string& symbol);

private:
    double simulatePrice(double& lastPrice);
};

#endif