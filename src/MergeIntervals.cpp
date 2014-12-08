// Given a collection of intervals, merge all overlapping intervals.

// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].



struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 

struct sortOperator{
     bool operator()(const Interval& lhs, const Interval& rhs) const{
        return (lhs.start==rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
    }
};
 
class Solution {
public:
   
    
    vector<Interval> merge(vector<Interval> &intervals) {
    
        vector<Interval> result;
    
        if (intervals.size() <= 0) return result;
        //sort the inervals. Note: using the customized comparing function.
        sort(intervals.begin(), intervals.end(), sortOperator());
        for(int i=0; i<intervals.size(); i++) { 
            int size = result.size();
            // if the current intervals[i] is overlapped with previous interval.
            // merge them together
            if( size>0 && result[size-1].end >= intervals[i].start) {
                result[size-1].end = max(result[size-1].end, intervals[i].end); 
            }else{
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};