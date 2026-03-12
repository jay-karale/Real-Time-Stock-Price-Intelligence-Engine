#include "APIClient.hpp"
#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

double APIClient::fetchPrice(const string& symbol) {

    CURL* curl;
    CURLcode res;
    string response;

    string apiKey = "XVLQ3MMKTU0EWGDW";

    string url =
        "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol="
        + symbol +
        "&apikey=" + apiKey;

    curl = curl_easy_init();

    if (curl) {

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            return -1;
        }

        string key = "\"05. price\": \"";
        size_t pos = response.find(key);

        if (pos != string::npos) {
            pos += key.length();
            size_t end = response.find("\"", pos);
            string priceStr = response.substr(pos, end - pos);
            return stod(priceStr);
        }
    }

    return -1;
}