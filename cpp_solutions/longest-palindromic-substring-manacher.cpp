
class Solution {
public:
    string preprocess(string s){
        int n = s.size();
        if(n==0) return "^$";
        string ret = "^";
        for(int i = 0; i < n; i++)
            ret += "#" + s.substr(i,1);
            
        ret += "#$";
        return ret;
    }
    
    string longestPalindrome(string s) {
        string T = preprocess(s);
        int n = T.size();
        int P[n];
        int c = 0, r = 0;

        for(int i = 1; i < n-1; i++){
            int i_mirror = 2*c-i;
            
            P[i] = (r>i) ? min(r-i,P[i_mirror]) : 0;

            while(T[i+1+P[i]] == T[i-1-P[i]])
                P[i]++;

            if(i+P[i]>r){
                c = i;
                r = i+P[i];
            }
        }

        int maxlen=0;
        int center=0;
        for(int i=1;i<n-1;i++){
            if(maxlen<P[i]){
                maxlen=P[i];
                center=i;
            }
        }
        
        return s.substr((center-1-maxlen)/2,maxlen);
    }
};
