class Solution {
public:
    void reverseWords(string &s) {
        string reversed;
        int i=s.size()-1;
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            if(i<0) break;
            if(reversed.size()) reversed.append(" ");
            int end=i;
            while(i>=0 && s[i]!=' ') i--;
            string temp=s.substr(i+1,end-i);
            reversed.append(temp);
        }
        s=reversed;
    }
};
