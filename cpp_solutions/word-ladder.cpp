class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(dict.empty()) return 0;
        int dist=1;
        queue<string> q;
        q.push(start);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string s=q.front();
                q.pop();
                for(int j=0;j<s.size();j++){
                    for(char c='a';c<='z';c++){
                        if(s[j]==c) continue;
                        char original=s[j];
                        s[j]=c;
                        if(s==end) return dist+1;
                        if(dict.count(s)>0){
                            dict.erase(s);
                            q.push(s);
                        }
                        s[j]=original;
                    }
                }
            }
            dist++;
        }
        return 0;
    }
};
