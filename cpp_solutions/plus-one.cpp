class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ret;
        int carry=1;
        while(!digits.empty()){
            ret.push_back((digits.back()+carry)%10);
            carry=(digits.back()+carry)/10;
            digits.pop_back();
        }
        if(carry>0)
            ret.push_back(carry);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
