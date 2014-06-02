class Solution {
public:
    bool isNumber(const char *s) {
        bool num=false;
        bool cansign=true;
        bool cane=false;
        bool space=false;
        bool numbegin=false;
        bool havee=false;
        bool candot=true;
        while(*s){
            char c=*s;
            s++;
            if(c==' '){
                if(numbegin) space=true;
                continue;
            }
            else if(space) return false;
            else if(c=='+' || c=='-'){
                if(!cansign) return false;
                cansign=false;
                numbegin=true;
                continue;
            }
            else if(c=='e'){
                if(!cane) return false;
                cane=false;
                havee=true;
                numbegin=true;
                num=false;
                cansign=true;
                candot=false;
                continue;
            }
            else if(c=='.'){
                if(!candot) return false;
                candot=false;
                numbegin=true;
                cansign=false;
                continue;
            }
            else if(c>='0' && c<='9'){
                num=true;
                numbegin=true;
                cansign=false;
                if(!havee) cane=true;
            }
            else return false;
        }
        return num;
        
    }
};
