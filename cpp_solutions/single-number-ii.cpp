class Solution {
public:
    int singleNumber(int A[], int n) {
        if(n<4) return A[0];
        short count[33]={0};
        for(int i=0;i<n;i++){
            unsigned int temp=0;
            if(A[i]<0){
                temp=-A[i];
                count[32]++;
                count[32]%=3;
            }
            else temp=A[i];
            
            int j=0;
            while(temp!=0){
                count[j]=(count[j]+(temp&1))%3;
                temp>>=1;
                j++;
            }
        }
        unsigned int res=0;
        for(int i=0;i<32;i++){
            if(count[i]!=0)
                res^=(1<<i);
        }
        
        return count[32]==0? res:-res;
    }
};
