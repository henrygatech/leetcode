class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s=="0") return 0;
        if(s.size()==1) return check1(s[0]);
        int fn=0, f1, f2;
        f2 = check1(s[0]);
        f1 = check1(s[0])*check1(s[1]) + check2(s[0],s[1]);
        for(int i=2;i<s.size();i++){
            if(check1(s[i])) fn+=f1;
            if(check2(s[i-1],s[i])) fn+=f2;
            f2=f1;
            f1=fn;
            fn=0;
        }
        return f1;
    }
    
    int check1(char c){
        return (c>='1' && c<='9')?1:0;
    }
    
    int check2(char c1, char c2){
        return (c1=='1' || c1=='2' && c2>='0' && c2<='6')?1:0;
    }
};
