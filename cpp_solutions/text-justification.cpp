class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> text;
        int cur=0;
        while(cur<words.size()){
            int beg=cur;
            int len=0;
            while(cur<words.size()){
                int newlen=len==0?words[cur].size():len+1+words[cur].size();
                if(newlen>L) break;
                len=newlen;
                cur++;
            }
            
            int space=L-len;
            int avgspace=0;
            if(cur-beg!=1 && cur<words.size()){
                avgspace=space/(cur-beg-1);
                space%=cur-beg-1;
            }
            
            string line;
            for(int i=beg;i<cur;i++){
                if(i==beg) line=words[i];
                else{
                    line+=' ';
                    for(int j=0;j<avgspace;j++) line+=' ';
                    if(space>0 && cur<words.size()){
                        line+=' ';
                        space--;
                    }
                    line+=words[i];
                }
            }
            for(int i=0;i<space;i++) line+=' ';
            text.push_back(line);
        }
        return text;
    }
};
