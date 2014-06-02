class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = m+n;
        if (len%2==1){
            return findkth(A,m,B,n,len/2+1);
        }
        else{
            return (findkth(A,m,B,n,len/2+1) + findkth(A,m,B,n,len/2))/2;
        }

    }
	
	double findkth(int A[], int m, int B[], int n, int k)
	{
		// make sure A is no bigger than B
		if(m>n) return findkth(B,n,A,m,k);
		// if A empty, find in B
		if(m==0) return B[k-1];
		// if to find the smallest, find between A[0] and B[0]
		if(k==1) return min(A[0],B[0]);
		
		// both A and B non-empty and to find at least the second smallest
		
		int apart = min(k/2,m);
		int bpart = k-apart;
		
		if(A[apart-1] < B[bpart-1])
			return findkth(A+apart,m-apart,B,n,k-apart);
		else
			return findkth(A,m,B+bpart,n-bpart,k-bpart);
	}
};
