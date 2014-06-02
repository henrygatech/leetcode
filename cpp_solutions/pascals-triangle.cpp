class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        vector<int> solution;
        if(numRows==0) return result;
        solution.push_back(1);
        result.push_back(solution);
        while(numRows>1){
            vector<int> last=result.back();
            solution.clear();
            solution.push_back(1);
            for(int i=1;i<last.size();i++)
                solution.push_back(last[i]+last[i-1]);
            solution.push_back(1);
            result.push_back(solution);
            numRows--;
        }
        return result;
    }
};
