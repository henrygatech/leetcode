class Solution {
public:
    bool canJump(int A[], int n) {
        if(n==1) return true;
        if(A[0]==0) return false;
        int start=0, end=0;
        while(start<=end){
            int max=0;
            for(int i=start;i<=end;i++){
                if(A[i]+i>=n-1) return true;
                if(A[i]+i>max) max=A[i]+i;
            }
            start=end+1;
            end=max;
        }
    }
};
