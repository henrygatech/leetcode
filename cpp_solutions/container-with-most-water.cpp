
class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0;
        int end = height.size()-1;
        int maxv = INT_MIN;
        
        while(start<end){
            int contain = min(height[start],height[end])*(end-start);
            maxv = max(maxv,contain);
            if(height[start]<=height[end])
                start++;
            else
                end--;
        }
        return maxv;
    }
};
