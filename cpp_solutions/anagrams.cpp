class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        int n=strs.size();
        if(n==0) return ret;
        
        vector<string> temp(strs);
        for(int i=0;i<n;i++)
            sort(temp[i].begin(),temp[i].end());
        
        map<string,vector<int> > ana;
        
        for(int i=0;i<n;i++)
            ana[temp[i]].push_back(i);
        
        auto p=ana.begin();
        while(p!=ana.end()){
            if(p->second.size()>1){
                while(!p->second.empty()){
                    ret.push_back(strs[p->second.back()]);
                    p->second.pop_back();
                }
            }
            p++;
        }
        
        return ret;
    }
};
