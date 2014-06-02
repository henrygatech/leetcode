class Solution {
public:
    int numDistinct(string S, string T) {
        if(S.empty() || T.empty()) return 0;
        int m=S.size();
        int n=T.size();
        vector<vector<int> > match(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
            match[i][0]=1;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                match[i][j]=match[i-1][j];
                if(S[i-1]==T[j-1])
                    match[i][j]+=match[i-1][j-1];
            }
        }
        return match[m][n];
    }
};
