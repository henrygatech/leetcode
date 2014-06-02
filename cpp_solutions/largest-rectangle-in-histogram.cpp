class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int area=0;
        stack<int> s;
        height.push_back(0);
        for(int i=0;i<height.size();i++){
            if(s.empty() || height[i]>height[s.top()]) s.push(i);
            else{
                int temp=s.top();
                s.pop();
                area=max(area,height[temp]*(s.empty()?i:i-s.top()-1));
                i--;
            }
        }
        return area;
    }
};
