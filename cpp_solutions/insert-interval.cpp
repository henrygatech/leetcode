/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        if(intervals.size()==0){
            result.push_back(newInterval);
            return result;
        }
        Interval val=newInterval;
        bool inserted=false;
        for(int i=0;i<intervals.size();i++){
            Interval next=intervals[i];
            if(val.end<next.start){
                if(!inserted){
                    result.push_back(val);
                    inserted=true;
                }
                result.push_back(next);
            }
            else if(next.end<val.start)
                result.push_back(next);
            else{
                val.start=min(val.start,next.start);
                val.end=max(val.end,next.end);
            }
        }
        if(!inserted) result.push_back(val);
        return result;
    }
};
