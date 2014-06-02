class Solution {
public:
    void sortColors(int A[], int n) {
        int zero=0, two=n-1, cur=0;
        while(cur<=two){
            if(A[cur]==0){
                swap(A[zero++],A[cur++]);
            }
            else if(A[cur]==2){
                swap(A[cur],A[two--]);
            }
            else
                cur++;
        }
    }
};
