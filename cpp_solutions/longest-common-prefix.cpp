
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string prefix;
        if(strs.size()==0) return prefix;
        int k=0;
        while(1){
            if(k==strs[0].size()) break;
            char p = strs[0][k];
            int i=0;
            for(;i<strs.size();i++){
                if(k==strs[i].size()) break;
                if(p!=strs[i][k]) break;
            }
            if(i!=strs.size()) break;
            prefix.append(1,p);
            k++;
        }
        return prefix;
    }
};
