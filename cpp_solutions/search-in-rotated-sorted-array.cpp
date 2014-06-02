class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left=0, right=n-1;
        while(left<=right){
            int mid = (right+left)/2;
            if(A[mid]==target) return mid;
            if(A[mid]>=A[left]){
                if(target>=A[left] && target<=A[mid]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else{
                if(target>=A[left] || target<=A[mid]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            
        }
        return -1;
    }
};
