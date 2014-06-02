class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2) return n;
        int count=1;
        int cur=1, i=1;
        while(i<n){
            if(A[i]==A[i-1]){
                if(count<2){
                    A[cur++]=A[i++];
                }
                else
                    i++;
                count++;
            }
            else{
                A[cur++]=A[i++];
                count=1;
            }
        }
        return cur;
    }
};
