
class Solution {
public:

    inline int c2n(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }


    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        for(int i=0; i<s.size(); i++){
            // if current symbol is greater than its previous
            // the value for these two symbol is the second-first
            if(i>0 && c2n(s[i])>c2n(s[i-1]))
                result+=c2n(s[i])-2*c2n(s[i-1]);
            else
                result+=c2n(s[i]);
        }
        return result;
    }
};
