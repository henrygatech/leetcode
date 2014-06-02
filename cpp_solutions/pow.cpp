class Solution {
public:
    double pow(double x, int n) {
        if(n==0 || x==1) return 1;
        if(x==0) return 0;
        
        int absn=abs(n);
        double result=x;
        int remain=0;
        int powind=1;
        while(absn/2!=0){
            result = result*result;
            remain += absn%2*powind;
            powind*=2;
            absn/=2;
        }
        
        result=result*pow(x,remain);
        if(n<0)
            result=1.0/result;
        return result;
    }
};
