#ifndef MAXMINTRACKER_HPP
#define MAXMINTRACKER_HPP
#include<queue>
#include<vector>

class MaxMinTracker{
    public:
       void storePrice(double price);
       void showMax()const;
       void showMin()const;

        private:
        std::priority_queue<double> maxHeap;
        std::priority_queue<double,std::vector<double>,std::greater<double>> minHeap;
};

#endif