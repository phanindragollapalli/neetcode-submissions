class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int minprice = INT_MAX;
        int maxprofit = INT_MIN;
        for(auto price : prices)
        {
            if(price<minprice)
            {
                minprice = price;
            }
            maxprofit = max(maxprofit,price-minprice);
        }
        return maxprofit;
    }
};