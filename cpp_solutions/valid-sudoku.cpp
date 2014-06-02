class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int row[9], col[9];
        for(int i=0;i<9;i++){
            memset(row,0,sizeof(row));
            memset(col,0,sizeof(col));
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(row[board[i][j]-'1']==1) return false;
                    row[board[i][j]-'1']++;
                }
                if(board[j][i]!='.'){
                    if(col[board[j][i]-'1']==1) return false;
                    col[board[j][i]-'1']++;
                }
            }
        }
        
        
        for(int i=0;i<9;i+=3)
            for(int j=0;j<9;j+=3){
                memset(row,0,sizeof(row));
                for(int k=0;k<3;k++)
                    for(int l=0;l<3;l++){
                        if(board[i+k][j+l]!='.'){
                            if(row[board[i+k][j+l]-'1']==1) return false;
                            row[board[i+k][j+l]-'1']++;
                        }
                    }
            }
        
        return true;
    }
};
