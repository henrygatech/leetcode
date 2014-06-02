class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int> > d(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
            d[i][0]=i;
        for(int i=1;i<=n;i++)
            d[0][i]=i;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    d[i][j]=d[i-1][j-1];
                else
                    d[i][j]=d[i-1][j-1]+1;
                d[i][j]=min(d[i][j],min(d[i-1][j],d[i][j-1])+1);
            }
        }
        return d[m][n];
    }
};
