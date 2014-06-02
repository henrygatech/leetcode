class Solution {
public:
    int trap(int A[], int n) {
        if(n<3) return 0;
        int lmh[n];
        int maxh=0;
        for(int i=0;i<n;i++){
            lmh[i]=maxh;
            maxh=max(maxh,A[i]);
        }
        int ret=0;
        maxh=A[n-1];
        for(int i=n-2;i>=0;i--){
            int top=min(maxh,lmh[i]);
            if(top>A[i]) ret+=top-A[i];
            maxh=max(maxh,A[i]);
        }
        return ret;
    }
};
