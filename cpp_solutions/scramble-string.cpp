class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        if(s1==s2) return true;
        int n=s1.size();
        bool dp[n+1][n][n];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[1][i][j]=s1[i]==s2[j]?true:false;
        
        for(int k=2;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                for(int j=0;j<=n-k;j++){
                    dp[k][i][j]=false;
                    for(int div=1;div<k && !dp[k][i][j];div++){
                        dp[k][i][j]=dp[div][i][j] && dp[k-div][i+div][j+div] ||
                            dp[div][i][j+k-div] && dp[k-div][i+div][j];
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};
