
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=s.size();
        int nmax=0;
        vector<int> stack;
        for(int i=0;i<n;i++){
            if(s[i]=='(') stack.push_back(i);
            else{
                if(!stack.empty() && s[stack.back()]=='('){
                    stack.pop_back();
                    nmax=max(nmax,i-(stack.empty()?-1:stack.back()));
                }
                else stack.push_back(i);
            }
        }
        return nmax;
    }
};
