
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        vector<vector<int>> result;
        if(num.size()<3) return result;
        for(int i=0;i<num.size()-2;i++){
            int j=i+1;
            int k=num.size()-1;
            while(j<k){
                int sum=num[i]+num[j]+num[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    vector<int> temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[j]);
                    temp.push_back(num[k]);
                    result.push_back(temp);
                    while(num[j]==num[j+1]) j++;
                    while(num[k]==num[k-1]) k--;
                    j++;
                    k--;
                }
                
            }
            while(num[i]==num[i+1]) i++;
        }
        return result;
    }
};
