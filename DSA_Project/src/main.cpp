#include<iostream>
#include<stdlib.h>
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
system("cls"); 

int main (){
   int n;
   cout <<" DSA Project - Real-Time-Stock-Price-Intelligence-System"<<endl;
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
    cout<<"Enter your Choice (0-9) : ";
    cin>>n;
    switch(n){
        case 1:
            cout<<" Price Stream Management Selected "<<endl;
            break;
        case 2:
            cout<<" Max/Min Price Tracking Selected "<<endl;
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
