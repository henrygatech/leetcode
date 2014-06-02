class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int> > paths(m,vector<int>(n,0));
        
        if(obstacleGrid[0][0]==0) paths[0][0]=1;
        
        for(int i=1;i<n;i++)
            if(obstacleGrid[0][i]==0)
                paths[0][i]=paths[0][i-1];
        
        for(int j=1;j<m;j++)
            if(obstacleGrid[j][0]==0)
                paths[j][0]=paths[j-1][0];
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0)
                    paths[i][j]=paths[i-1][j]+paths[i][j-1];
            }
        }
        
        return paths[m-1][n-1];
    }
};
