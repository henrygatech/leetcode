
class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign = 1;
        if(x<0)
            sign = -1;
            
        int remaining = sign*x;
        int lastdigit;
        int result = 0;
        
        while(remaining>0){
            lastdigit = remaining%10;
            remaining = remaining/10;
            result = 10 * result + lastdigit;        
        }
        
        // if overflow, return -1
        if(result<0) return -1;
        
        // if no overflow, return normal result
        return sign*result;
    }
};
