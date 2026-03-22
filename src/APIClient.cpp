#include "APIClient.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

double APIClient::fetchPrice(const string &symbol)
{
    static double lastPrice = 250.0;

    string apiKey = "XVLQ3MMKTU0EWGDW";

    string command =
        "curl -s \"https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + symbol +
        "&apikey=" + apiKey + "\" > temp_response.json";

    int ret = system(command.c_str());
    if (ret != 0)
        return simulatePrice(lastPrice);

    ifstream file("temp_response.json");
    if (!file.is_open())
        return simulatePrice(lastPrice);

    string result((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    remove("temp_response.json");

    if (result.find("Note") != string::npos ||
        result.find("Error Message") != string::npos ||
        result.find("Global Quote") == string::npos)
    {
        return simulatePrice(lastPrice);
    }

    string key = "\"05. price\": \"";
    size_t pos = result.find(key);

    if (pos != string::npos)
    {
        pos += key.length();
        size_t end = result.find("\"", pos);
        string priceStr = result.substr(pos, end - pos);

        try
        {
            double realPrice = stod(priceStr);
            if (realPrice > 0)
            {
                lastPrice = realPrice;
                double noise = ((double)rand() / RAND_MAX - 0.5) * 0.2;
                return realPrice + noise;
            }
        }
        catch (...)
        {
        }
    }

    return simulatePrice(lastPrice);
}

double APIClient::simulatePrice(double &lastPrice)
{
    double volatility = 0.01;
    double randomShock = ((double)rand() / RAND_MAX - 0.5) * volatility;

    lastPrice = lastPrice * exp(randomShock);

    if (lastPrice < 1.0)
        lastPrice = 1.0;

    return lastPrice;
}