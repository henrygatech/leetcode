class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n=gas.size(), start=-1;
        int sum=0, total=0;
        for(int i=0;i<n;i++){
            sum+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(sum<0){
                start=i;
                sum=0;
            }
        }
        return total>=0? start+1:-1;
    }
};
