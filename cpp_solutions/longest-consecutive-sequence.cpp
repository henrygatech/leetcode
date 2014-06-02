class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,pair<int,int>> range;
        int result=0;
        for(int n:num){
            if(range.find(n)!=range.end())
                continue;
            range[n]=make_pair(n,n);
            auto it=range.find(n-1);
            if(it!=range.end()){
                range[n].first=it->second.first;
                range[it->second.first].second=range[n].second;
                result=max(result,range[n].second-it->second.first);
            }
            it=range.find(n+1);
            if(it!=range.end()){
                range[range[n].first].second=it->second.second;
                range[it->second.second].first=range[n].first;
                result=max(result,it->second.second-range[n].first);
            }
        }
        return result+1;
    }
};
