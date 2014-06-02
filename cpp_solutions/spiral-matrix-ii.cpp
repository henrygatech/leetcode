class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n,vector<int>(n));
        spiral(result,n,1);
        return result;
    }
    
    void spiral(vector<vector<int> > &result, int n, int s){
        if(n==0) return;
        int start=(result.size()-n)/2;
        if(n==1){
            result[start][start]=s;
            return;
        }
        for(int i=0;i<n;i++)
            result[start][start+i]=s++;
        for(int i=1;i<n;i++)
            result[start+i][start+n-1]=s++;
        for(int i=n-2;i>=0;i--)
            result[start+n-1][start+i]=s++;
        for(int i=n-2;i>0;i--)
            result[start+i][start]=s++;
        
        spiral(result,n-2,s);
    }
};
