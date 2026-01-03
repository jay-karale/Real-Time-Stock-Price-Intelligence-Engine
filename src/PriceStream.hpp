#ifndef PRICESTREAM_HPP
#define PRICESTREAM_HPP
#include<vector>
 
class PriceStream{
    public :
        void AddPrice(double price);
        int GetPriceCount()const;

    private :
        std::vector<double>price;
 };
#endif 