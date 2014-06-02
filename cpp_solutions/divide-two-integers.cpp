
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return -1;
        bool neg=false;
        if(dividend<0 && divisor>0 || dividend>0 && divisor<0)  neg=true;
        
        unsigned int udividend=abs(dividend);
        unsigned int udivisor=abs(divisor);
        
        unsigned int res=div(udividend,udivisor);
        
        if(neg)   res=~res+1;
        return res;
    }
    
    unsigned int div(unsigned int dividend, unsigned int divisor){
        if(dividend<divisor) return 0;
        if(dividend==divisor) return 1;
        
        if(divisor<<1<=divisor)
            return div(dividend-divisor,divisor)+1;
        
        int bit=0, num=divisor<<1;
        while(dividend>num){
            if(num<<1>num){
                num<<=1;
                bit++;
            }
            else break;
        }
        return div(dividend-(divisor<<bit),divisor)+(1<<bit);
    }
};
