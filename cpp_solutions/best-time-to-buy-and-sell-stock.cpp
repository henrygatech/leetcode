class Solution {
public:
    int maxProfit(vector<int> &prices) {\
        if(prices.size()<=1) return 0;
        int minp=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(profit<prices[i]-minp)
                profit=prices[i]-minp;
            minp=min(minp,prices[i]);
        }
        return profit;
    }
};
