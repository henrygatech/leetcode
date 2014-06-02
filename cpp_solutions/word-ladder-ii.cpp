class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > result;
        if(dict.empty()) return result;
        unordered_set<string> q, to_delete;
        unordered_map<string,vector<string>> prev;
        q.insert(start);
        to_delete.insert(start);
        bool reached=false;
        while(!q.empty() && !reached){
            for(auto iter=to_delete.begin();iter!=to_delete.end();iter++)
                dict.erase(*iter);
            q=to_delete;
            to_delete.clear();
            
            for(auto iter=q.begin();iter!=q.end();iter++){
                string s=*iter;
                for(int j=0;j<s.size();j++){
                    string news=s;
                    for(char c='a';c<='z';c++){
                        if(news[j]==c) continue;
                        news[j]=c;
                        if(dict.count(news)>0){
                            prev[news].push_back(s);
                            to_delete.insert(news);
                        }
                        if(news==end)
                            reached=true;
                    }
                }
            }
        }
        if(reached){
            vector<string> path;
            gen(prev,path,result,end);
        }
        return result;
    }
    
    void gen(unordered_map<string,vector<string>> &prev, vector<string> &path, vector<vector<string>> &result, string word){
        if(prev[word].size()==0){
            path.push_back(word);
            vector<string> curpath=path;
            reverse(curpath.begin(),curpath.end());
            result.push_back(curpath);
            path.pop_back();
            return;
        }
        
        path.push_back(word);
        for(int i=0;i<prev[word].size();i++)
            gen(prev,path,result,prev[word][i]);
        path.pop_back();
    }
};
