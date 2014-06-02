class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        if(m+n!=s3.size()) return false;
        vector<vector<bool>> match(m+1,vector<bool>(n+1,false));
        match[0][0]=true;
        
        for(int i=1;i<=m;i++)
            if(s1[i-1]==s3[i-1])
                match[i][0]=match[i-1][0];
        
        for(int i=1;i<=n;i++)
            if(s2[i-1]==s3[i-1])
                match[0][i]=match[0][i-1];
        
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s3[i+j-1])
                    match[i][j] = match[i][j] || match[i-1][j];
                if(s2[j-1]==s3[i+j-1])
                    match[i][j] = match[i][j] || match[i][j-1];
            }
        
        return match[m][n];
    }
};
