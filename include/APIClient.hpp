#ifndef APICLIENT_HPP
#define APICLIENT_HPP

#include <string>

class APIClient {
public:
    double fetchPrice(const std::string& symbol);
};

#endif