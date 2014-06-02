
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        int start = 0;
        int maxlen = 1;
        bool table[1000][1000] = {false};
        
        // diagonal, length = 1
        for(int i=0;i<n;i++)
            table[i][i] = true;
            
        // second diagonal, length = 2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                table[i][i+1] = true;
                start = i;
                maxlen = 2;
            }
        }
        
        // all others, length >= 3
        for(int len=3;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(s[i]==s[j] && table[i+1][j-1]){
                    table[i][j] = true;
                    start = i;
                    maxlen = len;
                }
            }
        }
        
        return s.substr(start, maxlen);
        
    }
};
