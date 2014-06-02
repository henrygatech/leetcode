class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row=triangle.size();
        if(row==0) return 0;
        vector<int> minv(triangle[row-1].size());
        
        for(int i=row-1; i>=0; i--){
            int col=triangle[i].size();
            for(int j=0;j<col;j++){
                if(i==row-1){
                    minv[j]=triangle[i][j];
                    continue;
                }
                minv[j]=min(minv[j],minv[j+1])+triangle[i][j];
            }
        }
        return minv[0];
    }
};
