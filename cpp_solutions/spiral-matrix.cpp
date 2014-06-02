class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int m=matrix.size();
        if(m==0) return result;
        int n=matrix[0].size();
        if(n==0) return result;
        spiral(matrix,result,m,n);
        return result;
    }
    
    void spiral(vector<vector<int> > &matrix, vector<int> &result, int m, int n){
        if(m==0 || n==0) return;
        
        int row=(matrix.size()-m)/2;
        int col=(matrix[0].size()-n)/2;
        if(m==1){
            for(int i=0;i<n;i++)
                result.push_back(matrix[row][col+i]);
            return;
        }
        if(n==1){
            for(int i=0;i<m;i++)
                result.push_back(matrix[row+i][col]);
            return;
        }
        
        for(int i=0;i<n;i++)
            result.push_back(matrix[row][col+i]);
        
        for(int i=1;i<m;i++)
            result.push_back(matrix[row+i][col+n-1]);
        
        for(int i=n-2;i>=0;i--)
            result.push_back(matrix[row+m-1][col+i]);
        
        for(int i=m-2;i>0;i--)
            result.push_back(matrix[row+i][col]);
        
        spiral(matrix,result,m-2,n-2);
    }
};
