class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int idx = binsearch(A,0,n-1,target);
        
        if(idx>=0) return idx;
        else return -idx;
    }
    
    int binsearch(int a[], int left, int right, int target){
        if(left>right) return -left;
        int mid = (left+right)/2;
        if(a[mid]==target) return mid;
        if(a[mid]>target)
            binsearch(a,left,mid-1,target);
        else
            binsearch(a,mid+1,right,target);
    }
};
