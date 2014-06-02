class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len=0;
        while(*s!='\0'){
            while(*s==' ') s++;
            if(*s=='\0') break;
            else len=0;
            while(*s!='\0' && *s!=' '){
                len++;
                s++;
            }
        }
        return len;
    }
};
