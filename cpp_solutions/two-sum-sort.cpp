
struct node
{
    int value;
    int index;
    node(){}
    node(int val, int ind): value(val), index(ind){}
};

bool compare(const node &a, const node &b)
{
    return a.value < b.value;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<node> temp;
        for (int i=0; i < numbers.size(); ++i){
            temp.push_back(node(numbers[i],i+1));
        }
        sort(temp.begin(),temp.end(),compare);
        
        int i=0;
        int j=temp.size()-1;
        
        while(i<j){
            
            int sum = temp[i].value + temp[j].value;
            if(sum == target){
                vector<int> answer;
                int ind1 = min(temp[i].index, temp[j].index);
                int ind2 = max(temp[i].index, temp[j].index);
                answer.push_back(ind1);
                answer.push_back(ind2);
                return answer;
            }
            else if(sum < target)   ++i;
            else    --j;
        }
        
    }
};
