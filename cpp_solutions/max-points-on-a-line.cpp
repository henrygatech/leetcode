/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    bool sameline(Point a, Point b, Point c){
        return (a.y-b.y)*(c.x-b.x)==(a.x-b.x)*(c.y-b.y);
    }
    
    bool allsame(vector<Point> &points){
        int i=0;
        while(i<points.size()){
            if(points[i].x!=points[0].x || points[i].y!=points[0].y)
                break;
            i++;
        }
        return i==points.size();
    }

    int maxPoints(vector<Point> &points) {
        if(points.size()<=1 || allsame(points))
            return points.size();
        
        int maxPoints=2;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                if(points[i].x==points[j].x && points[i].y==points[j].y)
                    continue;
                int count=2;
                for(int k=0;k<points.size();k++){
                    if(i!=k && j!=k && sameline(points[i],points[j],points[k]))
                        count++;
                }
                maxPoints=max(maxPoints,count);
            }
        }
        return maxPoints;
    }
};
