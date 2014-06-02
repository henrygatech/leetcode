class Solution {
public:
    int jump(int A[], int n) {
        if(n<2) return 0;
        int start=0, end=0, count=0;
        while(end<n){
            int max=0;
            count++;
            for(int i=start;i<=end;i++){
                if(A[i]+i>=n-1) return count;
                if(A[i]+i>max) max=A[i]+i;
            }
            start=end+1;
            end=max;
        }
    }
};
