
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        int last = num.size()-1;
        vector<vector<int>> result;
        for(int i=0; i<last-2; i++){
            for(int j=i+1; j<last-1; j++){
                int k=j+1;
                int l=last;
                while(k<l){
                    int sum=num[i]+num[j]+num[k]+num[l];
                    if(sum==target){
                        vector<int> solution;
                        solution.push_back(num[i]);
                        solution.push_back(num[j]);
                        solution.push_back(num[k]);
                        solution.push_back(num[l]);
                        result.push_back(solution);
                        k++;l--;
                        while(k<l && num[k]==num[k-1]) k++;
                        while(k<l && num[l]==num[l+1]) l--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
                
                while(j<last-1 && num[j]==num[j+1]) j++;
            }
            
            while(i<last-2 && num[i]==num[i+1]) i++;
        }
        return result;
    }
};
