class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n=s.size();
        vector<bool> b(n+1,false);
        b[0]=true;
        
        for(int i=0;i<n;i++){
            int j=i;
            while(j>=0){
                string temp=s.substr(j,i-j+1);
                if(b[j] && dict.count(temp)>0){
                    b[i+1]=true;
                    break;
                }
                j--;
            }
        }
        
        return b[n];
    }
};
