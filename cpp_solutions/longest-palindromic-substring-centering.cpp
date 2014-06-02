
class Solution {
public:

    string expand(string s, int a, int b){
        int l=a, r=b;
        int n=s.size();
        while(l>=0 && r<=n-1 && s[l]==s[r]){
            l--; r++;
        }
        return s.substr(l+1,r-1-l);
    }
    
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=s.size();
        if(n==0) return "";
        string longest=s.substr(0,1);
        for(int i=0;i<n-1;i++){
            string p1=expand(s,i,i);
            if(p1.size()>longest.size())
                longest=p1;
                
            string p2=expand(s,i,i+1);
            if(p2.size()>longest.size())
                longest=p2;
        }
        return longest;
    }
};
