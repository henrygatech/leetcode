struct position{
    int row;
    int col;
    position(){}
    position(int i, int j):row(i), col(j){}
};


class Solution {
public:
    bool valid(vector<vector<char> > &board, position &p){
        char val=board[p.row][p.col];
        if(val<'1' || val>'9') return false;
        for(int i=0;i<9;i++)
            if(board[i][p.col]==val && board[i][p.col]!='.' && i!=p.row ||
               board[p.row][i]==val && board[p.row][i]!='.' && i!=p.col )
                return false;
        
        int a=p.row/3*3;
        int b=p.col/3*3;
        for(int i=a;i<a+3;i++)
            for(int j=b;j<b+3;j++)
                if(board[i][j]==val && board[i][j]!='.' && i!=p.row && j!=p.col)
                    return false;
        
        return true;
    }


    void solveSudoku(vector<vector<char> > &board) {
        if(board.size()!=9 || board[0].size()!=9) return;
        vector<position> pts;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]=='.')
                    pts.push_back(position(i,j));
        
        if(pts.empty()) return;
        
        int cur=0;
        bool forward=true;
        board[pts[0].row][pts[0].col]='1';
        while(cur<pts.size()){
            position &p=pts[cur];
            if(forward){
                if(valid(board,p)) cur++;
                else forward=false;
            }
            else{
                char &c=board[p.row][p.col];
                if(c=='9'){
                    c='.';
                    cur--;
                }
                else{
                    c++;
                    forward=true;
                }
            }
        }
    }
};
