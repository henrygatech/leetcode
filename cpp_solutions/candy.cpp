class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.size()==0) return 0;
        int n=ratings.size();
        vector<int> count(n,1);
        int total=0;
        
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                count[i]=count[i-1]+1;
        }
        
        for(int i=n-1;i>=1;i--){
            total+=count[i];
            if(ratings[i-1]>ratings[i] && count[i-1]<=count[i])
                count[i-1]=count[i]+1;
        }
        
        total+=count[0];
        return total;
    }
};
