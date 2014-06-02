
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = num.size();
        if(size<=1) return;
        
        int index = size-1;
        while(--index>=0 && num[index]>=num[index+1]);
        if(index>=0){
            int i = size-1;
            while(num[index]>=num[i]){
                i--;
            }
            swap(num[index],num[i]);
            reverse(num.begin()+index+1,num.end());
        }
        else{
            reverse(num.begin(),num.end());
        }
    }
};
