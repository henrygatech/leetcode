class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m=board.size();
        if(m==0) return false;
        int n=board[0].size();
        if(n==0) return false;
        if(word.size()==0) return true;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    bool found=find(board,i,j,word,0);
                    if(found) return true;
                }
            }
        }
        return false;
    }
    
    bool find(vector<vector<char> > &board, int i, int j, string word, int start){
        if(start==word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[start])
            return false;
        
        board[i][j]='#';
        bool found = find(board,i-1,j,word,start+1) ||
                     find(board,i+1,j,word,start+1) ||
                     find(board,i,j-1,word,start+1) ||
                     find(board,i,j+1,word,start+1);
        board[i][j]=word[start];
        return found;
    }
};
