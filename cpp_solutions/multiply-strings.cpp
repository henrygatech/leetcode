class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty()) return "0";
        int m=num1.size();
        int n=num2.size();
        string ret(m+n+1,'0');
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<m;i++){
            int d1=num1[i]-'0';
            int carry=0;
            for(int j=0;j<n;j++){
                int d2=num2[j]-'0';
                int cur=ret[i+j]-'0';
                ret[i+j]=(d1*d2+carry+cur)%10+'0';
                carry=(d1*d2+carry+cur)/10;
            }
            if(carry>0)
                ret[i+n]=carry+'0';
        }
        
        reverse(ret.begin(),ret.end());
        int i=0;
        while(i<ret.size() && ret[i]=='0') i++;
        if(i==ret.size()) return "0";
        else return ret.substr(i);
    }
};
