class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        int A[n];
        nqueens(A,0,n,result);
        return result;
    }
    
    void nqueens(int A[], int row, int n, vector<vector<string> > &result){
        if(row==n) qprint(A,n,result);
        else{
            for(int i=0;i<n;i++){
                A[row]=i;
                if(valid(A,row))
                    nqueens(A,row+1,n,result);
            }
        }
    }
    
    bool valid(int A[], int row){
        for(int i=0;i<row;i++){
            if(A[i]==A[row] || abs(A[i]-A[row])==row-i)
                return false;
        }
        return true;
    }
    
    void qprint(int A[], int n, vector<vector<string> > &result){
        vector<string> sol;
        for(int i=0;i<n;i++){
            string line(n,'.');
            line[A[i]]='Q';
            sol.push_back(line);
        }
        result.push_back(sol);
    }
};
