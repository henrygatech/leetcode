
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::sort(num.begin(),num.end());
        int len = num.size()-1;
        int minV = INT_MAX;
        int record;
        for(int i=0 ; i<len; i++){
            int start=i+1;
            int end=len;
            while(start<end){
                int sum=num[i]+num[start]+num[end];
                if(sum==target){
                    minV = 0;
                    record = sum;
                    break;
                }
                if(sum<target){
                    if(target-sum<minV){
                        minV = target-sum;
                        record = sum;
                    }
                    start++;
                }
                else{
                    if(sum-target<minV){
                        minV = sum-target;
                        record = sum;
                    }
                    end--;
                }
                while(i<len-1 && num[i]==num[i+1]) i++;
            }
        }
        return record;
    }
};
