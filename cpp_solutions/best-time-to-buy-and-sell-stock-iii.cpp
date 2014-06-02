class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        if(n<2) return 0;
        vector<int> max1(n,0);
        int maxprofit=0;
        int lmin=prices[0];
        for(int i=1;i<n;i++){
            int profit=prices[i]-lmin;
            if(profit>maxprofit) maxprofit=profit;
            max1[i]=maxprofit;
            lmin=min(lmin,prices[i]);
        }
        
        int ret=max1[n-1];
        int high=prices[n-1];
        maxprofit=0;
        for(int i=n-2;i>=0;i--){
            int profit=high-prices[i];
            if(profit>maxprofit) maxprofit=profit;
            if(maxprofit+max1[i]>ret)
                ret=maxprofit+max1[i];
            high=max(high,prices[i]);
        }
        return ret;
    }
};
