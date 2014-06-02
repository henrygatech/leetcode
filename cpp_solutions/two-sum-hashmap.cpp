
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> m;
        for(int i=0;i<numbers.size();i++)
            m[numbers[i]]=i;
            
        for(int i=0;i<numbers.size();i++){
            int rem=target-numbers[i];
            if(m.find(rem)!=m.end() && i!=m[rem]){
                vector<int> res;
                res.push_back(i+1);
                res.push_back(m[rem]+1);
                return res;
            }
        }
        
    }
};
