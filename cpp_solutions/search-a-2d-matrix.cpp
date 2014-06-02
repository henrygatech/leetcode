class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(target<matrix[0][0] || target>matrix[m-1][n-1]) return false;
        
        int start=0, end=m-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(matrix[mid][0]==target) return true;
            if(matrix[mid][0]>target) end=mid-1;
            else start=mid+1;
        }
        int row=end;
        
        start=0, end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(matrix[row][mid]==target) return true;
            if(matrix[row][mid]>target) end=mid-1;
            else start=mid+1;
        }
        return false;
    }
};
