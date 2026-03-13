#include "APIClient.hpp"
#include <iostream>
#include <cstdio>
#include <memory>
#include <array>
#include <string>
#include <stdio.h>
#include <process.h>

using namespace std;

#include "APIClient.hpp"
#include <iostream>
#include <cstdio>
#include <memory>
#include <array>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

double APIClient::fetchPrice(const string& symbol) {

    string apiKey = "XVLQ3MMKTU0EWGDW";

    string command =
    "curl \"https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol="
    + symbol +
    "&apikey=" + apiKey + "\" > temp_response.json";

    int ret = system(command.c_str());
    if (ret != 0) return -1;

    ifstream file("temp_response.json");
    if (!file.is_open()) return -1;

    string result((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

   
    remove("temp_response.json");

    string key = "\"05. price\": \"";
    size_t pos = result.find(key);

    if (pos != string::npos) {
        pos += key.length();
        size_t end = result.find("\"",pos);
        string price = result.substr(pos,end-pos);
        return stod(price);
    }

    return -1;
}