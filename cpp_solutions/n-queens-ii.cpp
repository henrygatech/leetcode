class Solution {
public:
    int totalNQueens(int n) {
        int count=0;
        int A[n];
        nqueens(A,0,n,count);
        return count;
    }
    
    void nqueens(int A[], int row, int n, int &count){
        if(row==n){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            A[row]=i;
            if(valid(A,row))
                nqueens(A,row+1,n,count);
        }
    }
    
    bool valid(int A[], int row){
        for(int i=0;i<row;i++)
            if(A[i]==A[row] || abs(A[i]-A[row])==row-i)
                return false;
        
        return true;
    }
};
