class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()) return b;
        if(b.empty()) return a;
        string ret;
        int carry=0;
        while(!a.empty() && !b.empty()){
            int c1=a.back()-'0';
            int c2=b.back()-'0';
            a.pop_back();
            b.pop_back();
            ret.push_back((c1+c2+carry)%2+'0');
            carry=(c1+c2+carry)/2;
        }
        
        while(!a.empty()){
            int c1=a.back()-'0';
            a.pop_back();
            ret.push_back((c1+carry)%2+'0');
            carry=(c1+carry)/2;
        }
        
        while(!b.empty()){
            int c2=b.back()-'0';
            b.pop_back();
            ret.push_back((c2+carry)%2+'0');
            carry=(c2+carry)/2;
        }
        if(carry>0)
            ret.push_back(carry+'0');
        
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
