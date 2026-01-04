#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#include"PriceStream.hpp"
#include"MaxMinTracker.hpp"
#include"MedianTracker.hpp"
#include"SlidingWindowMedian.hpp"
#include"MovingAverage.hpp"
#include"VolatilityTracker.hpp"
#include"AnomalyDetector.hpp"
#include"OrderBook.hpp"
#include"Utils.hpp"

using namespace std;

void PriceStream::AddPrice(double p){
    price.push_back(p);
}
int PriceStream::GetPriceCount()const{
    return price.size();
}


void MaxMinTracker::storePrice(double price) {
    maxHeap.push(price);
    minHeap.push(price);
}

void MaxMinTracker::showMax() const {
    if (!maxHeap.empty()) {
        cout<<"Current Max Price :"<<maxHeap.top()<<endl;
    } else {
        cout << "No Prices Available" <<endl;
    }
}

void MaxMinTracker::showMin() const {
    if (!minHeap.empty()) {
        cout<<"Current Min Price :"<<minHeap.top()<<endl;
    } else {
        cout << "No Prices Available" << endl;
    }
}

int main (){
  
   int n;

   PriceStream ps;
   MaxMinTracker mm;

   cout <<"DSA Project - Real-Time-Stock-Price-Intelligence-System"<<endl;
   cout<<" -----------------------------------------------------"<<endl;
   cout<<" | 1. Price Stream Management                        |"<<endl;
   cout<<" | 2. Max/Min Price Tracking                         |"<<endl;            
   cout<<" | 3. Median Price Tracking                          |"<<endl;
   cout<<" | 4. Sliding Window Median Calculation              |"<<endl;
   cout<<" | 5. Moving Average Calculation                     |"<<endl;
   cout<<" | 6. Volatility Tracking                            |"<<endl;
   cout<<" | 7. Anomaly Detection                              |"<<endl;
   cout<<" | 8. Order Book Management                          |"<<endl;
   cout<<" | 9. Utility Functions                              |"<<endl;
   cout<<" | 10. Exit                                          |"<<endl;
   cout<<" -----------------------------------------------------"<<endl;

   while(true){
    cout<<"Enter your Choice (1-10) : ";
    string line;
    getline(cin, line);
    stringstream ss(line);
    if(!(ss >> n)){
        cout<<"Invalid choice, try again"<<endl;
        continue;
    }
    switch(n){
        case 1:{
            cout<<" Price Stream Management Selected "<<endl;
            int subchoice;
            while(true){
                cout << "1. Add Prices (multiple separated by spaces)" << endl;
                cout << "2. Get Price Count" << endl;
                cout << "3. Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                string line;
                getline(cin, line);
                stringstream ss(line);
                if(!(ss >> subchoice)){
                    cout << "Invalid choice, try again." << endl;
                    continue;
                }
                if(subchoice == 1){
                    cout << "Enter prices (separated by spaces) : ";
                    getline(cin, line);
                    stringstream ss2(line);
                    double p;
                    int count = 0;
                    while(ss2 >> p){
                        ps.AddPrice(p);
                        mm.storePrice(p);
                        count++;
                    }
                    cout << count << "Prices added successfully." << endl;
                } else if(subchoice == 2){
                    cout << "Current price count: " << ps.GetPriceCount() << endl;
                } else if(subchoice == 3){
                    break;
                } else {
                    cout << "Invalid choice, try again." << endl;
                }
            }
            break;
        }
        case 2:
            cout<<" Max/Min Price Tracking Selected "<<endl;
            mm.showMax();
            mm.showMin();
            break;
        case 3:
            cout<<" Median Price Tracking Selected "<<endl;
            break;  
        case 4:
            cout<<" Sliding Window Median Calculation Selected "<<endl;
            break;
        case 5:
            cout<<" Moving Average Calculation Selected "<<endl;
            break;
        case 6:
            cout<<" Volatility Tracking Selected "<<endl;
            break;
        case 7:
            cout<<" Anomaly Detection Selected "<<endl;
            break;
        case 8:
            cout<<" Order Book Management Selected "<<endl;
            break;  
        case 9:
            cout<<" Utility Functions Selected "<<endl;
            break;
        case 10:
            cout<<" Exiting Program "<<endl;
            exit(0);
            break;
        default:
            cout<<" Invalid Choice , Please try again"<<endl;
            break;
    }

   }

   return 0;
}
