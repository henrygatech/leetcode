class Solution {
public:
    int numTrees(int n) {
        int nums[n+1];
        nums[0]=1;
        nums[1]=1;
        for(int i=2;i<=n;i++){
            nums[i]=0;
            for(int j=0;j<i;j++){
                nums[i]+=nums[j]*nums[i-1-j];
            }
        }
        return nums[n];
    }
};
