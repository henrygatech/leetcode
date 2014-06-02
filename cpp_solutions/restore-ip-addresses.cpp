class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        restore(result,ip,0,0,s);
        return result;
    }
    
    void restore(vector<string> &result, string ip, int start, int part, string s){
        if(s.size()-start>3*(4-part)) return;
        if(s.size()-start<4-part) return;
        if(start==s.size() && part==4){
            ip.pop_back();
            result.push_back(ip);
            return;
        }
        int num=0;
        for(int i=start;i<start+3;i++){
            num=10*num+s[i]-'0';
            if(num<=255){
                ip+=s[i];
                restore(result,ip+'.',i+1,part+1,s);
            }
            if(num==0) break;
        }
    }
};
