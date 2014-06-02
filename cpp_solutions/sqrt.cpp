class Solution {
public:
    int sqrt(int x) {
        int start=0, end;
        end=x/2<std::sqrt(INT_MAX)?x/2+1:std::sqrt(INT_MAX);
        while(start<=end){
            int mid=(start+end)/2;
            if(x==mid*mid) return mid;
            else if(x<mid*mid) end=mid-1;
            else start=mid+1;
        }
        return end;
    }
};
