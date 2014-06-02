
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, i = 0, j = 0, n = s.size();
        bool exist[256] = {false};
        while(i<n){
            if(exist[s[i]]){
                maxlen = max(maxlen, i-j);
                while(s[j]!=s[i]){
                    exist[s[j]] = false;
                    j++;
                }
                i++;
                j++;
            }
            else{
                exist[s[i]] = true;
                i++;
            }
        }
        
        maxlen = max(maxlen, n-j);
        return maxlen;
    }
};
