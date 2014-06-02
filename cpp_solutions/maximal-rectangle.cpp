class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int area=0;
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        if(n==0) return 0;
        vector<int> hist(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') hist[j]++;
                else hist[j]=0;
            }
            area=max(area,largest(hist));
        }
        return area;
    }
    
    int largest(vector<int> hist){
        int area=0;
        stack<int> s;
        hist.push_back(0);
        for(int i=0;i<hist.size();i++){
            if(s.empty() || hist[i]>hist[s.top()]) s.push(i);
            else{
                int temp=s.top();
                s.pop();
                area=max(area,hist[temp]*(s.empty()?i:i-s.top()-1));
                i--;
            }
        }
        return area;
    }
};
