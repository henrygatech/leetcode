class Solution {
public:
    int climbStairs(int n) {
        int f2=1, f1=2;
        if(n==1) return f2;
        if(n==2) return f1;
        int f;
        for(int i=3;i<=n;i++){
            f=f1+f2;
            f2=f1;
            f1=f;
        }
        return f;
    }
};
