struct node{
    int x;
    int y;
    node(){}
    node(int i, int j):x(i), y(j){}
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        if(n==0) return;
        queue<node> q;
        
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') q.push(node(i,0));
            if(board[i][n-1]=='O') q.push(node(i,n-1));
        }
        
        for(int i=0;i<n;i++){
            if(board[0][i]=='O') q.push(node(0,i));
            if(board[m-1][i]=='O') q.push(node(m-1,i));
        }
        
        while(!q.empty()){
            int i=q.front().x;
            int j=q.front().y;
            q.pop();
            board[i][j]='#';
            
            if(i>1 && board[i-1][j]=='O') q.push(node(i-1,j));
            if(i<m-1 && board[i+1][j]=='O') q.push(node(i+1,j));
            if(j>1 && board[i][j-1]=='O') q.push(node(i,j-1));
            if(j<n-1 && board[i][j+1]=='O') q.push(node(i,j+1));
        }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
    }
};
