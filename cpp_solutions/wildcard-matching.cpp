class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *star=NULL;
        const char *ss=s;
        while(*s!='\0'){
            if(*p==*s || *p=='?'){
                s++;
                p++;
            }
            else if(*p=='*'){
                star=p++;
                ss=s;
            }
            else if(star){
                p=star+1;
                s=++ss;
            }
            else 
                return false;
        }
        while(*p=='*') p++;
        return *p=='\0';
    }
};
