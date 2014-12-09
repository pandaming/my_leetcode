// Given a set of non-overlapping intervals, 
// insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].


 
struct sortOperator{
     bool operator()(const Interval& lhs, const Interval& rhs) const{
        return (lhs.start==rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	intervals.push_back(newInterval);
    	return merge(intervals);
    }

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