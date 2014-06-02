class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        int num[n];
        int perm=1;
        for(int i=0;i<n;i++){
            num[i]=i+1;
            perm*=i+1;
        }
        
        k--;
        for(int i=0;i<n;i++){
            perm/=n-i;
            int digit=k/perm;
            s.append(1,num[digit]+'0');
            for(int j=digit;j<n-i;j++)
                num[j]=num[j+1];
            k%=perm;
        }
        return s;
    }
};
