class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        int D[n+1];
        bool P[n][n];
        
        for(int i=0;i<=n;i++)
            D[i]=n-i-1;
            
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                P[i][j]=false;
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (P[i+1][j-1] || j-i<2)){
                    P[i][j]=true;
                    D[i]=min(D[i],1+D[j+1]);
                }
            }
        }
        return D[0];
    }
};
