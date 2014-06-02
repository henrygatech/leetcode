
class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(str);
        int sign = 1, operator_count = 0;
        const char* p = str;
        
        // ignore spaces
        while (*p==' ')
            p++;
        
        // count number of operatores
        while (*p=='-'){
            sign = -1;
            operator_count++;
            p++;
        }
        
        while (*p=='+'){
            operator_count++;
            p++;
        }
        
        // multiple signs invalid
        if(operator_count>1) return 0;
        
        // now construct the number
        int result = 0;
        while(*p!='\0'){
            if(*p<'0' ||*p>'9')
                break;
            if(result > INT_MAX/10)
                return sign==-1?INT_MIN:INT_MAX;
            if(result == INT_MAX/10 && INT_MAX%10 < (*p-'0'))
                return sign==-1?INT_MIN:INT_MAX;
            
            result = 10*result + (*p-'0');
            p++;
        }
        return sign*result;
        
    }
};
