class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int idx = binsearch(A,0,n-1,target);
        vector<int> result;
        if(idx==-1){
            result.push_back(-1);
            result.push_back(-1);
        }
        else{
            int i=idx;
            while( i>0 && A[i-1]==A[idx]) i--;
            result.push_back(i);
            i = idx;
            while( i<n-1 && A[i+1]==A[idx]) i++;
            result.push_back(i);
            
            
        }
        return result;
    }
    
    int binsearch(int a[], int left, int right, int target){
        if(left>right) return -1;
        int mid = (left+right)/2;
        if(a[mid]==target) return mid;
        if(a[mid]<target)
            binsearch(a,mid+1,right,target);
        else
            binsearch(a,left,mid-1,target);
    }
};
