class Solution {
public:
    string countAndSay(int n) {
        string pre("1");
        while(n>1){
            string cur("");
            int i=0, count=0;
            char c=pre[0];
            while(i<=pre.size()){
                if(c==pre[i]){
                    count++;
                    i++;
                }else{
                    cur.append(1,count+'0');
                    cur.append(1,c);
                    count=0;
                    c=pre[i];
                }
            }
            pre=cur;
            n--;
        }
        return pre;
    }
};
