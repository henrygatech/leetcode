
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        string sample;
        if(n!=0)
            par(result,sample,0,n,0,0);
        return result;
    }

    void par(vector<string>& result, string& sample, int total, int n, int left, int right){
        if(total==2*n){
            result.push_back(sample);
            return;
        }
        if(left<n){
            sample.push_back('(');
            par(result,sample,total+1,n,left+1,right);
            sample.resize(sample.size()-1);
        }
        if(right<left){
            sample.push_back(')');
            par(result,sample,total+1,n,left,right+1);
            sample.resize(sample.size()-1);
        }
    }

};
