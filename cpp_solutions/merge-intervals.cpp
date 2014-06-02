/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(const Interval &a, const Interval &b){
    return a.start<b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if(intervals.size()==0) return result;
        
        sort(intervals.begin(),intervals.end(),comp);
        Interval val=intervals[0];
        for(int i=1;i<intervals.size();i++){
            Interval next=intervals[i];
            if(val.end<next.start){
                result.push_back(val);
                val=next;
            }else{
                val.end=max(val.end,next.end);
            }
        }
        result.push_back(val);
        return result;
    }
};
