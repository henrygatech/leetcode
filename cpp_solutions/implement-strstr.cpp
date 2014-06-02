
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int haylen = strlen(haystack);
        int neelen = strlen(needle);
        
        for(int i=0;i<=haylen-neelen;i++){
            char *p1=haystack+i;
            char *p2=needle;
            while(*p2!='\0'){
                if(*p1!=*p2) break;
                else{
                    p1++;
                    p2++;
                }
            }
            if(*p2=='\0') return haystack+i;

        }
        return NULL;
    }
};
