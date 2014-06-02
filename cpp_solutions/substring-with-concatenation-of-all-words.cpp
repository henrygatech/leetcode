
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, int> expect;
        map<string, int> count;
        for(int i=0;i<L.size();i++)
            expect[L[i]]++;
        
        vector<int> result;
        if(L.size()==0) return result;
        int row = L.size();
        int len = L[0].size();
        for(int i=0; i<=(int)S.size()-len*row; i++){
            count.clear();
            int j=0;
            for(;j<row;j++){
                string sub = S.substr(i+j*len,len);
                if(expect.find(sub)!=expect.end()){
                    count[sub]++;
                }
                else break;
                if(count[sub]>expect[sub]) break;
            }
            if(j==row) result.push_back(i);
        }
        return result;
    }
};
