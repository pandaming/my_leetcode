// Follow up for "Find Minimum in Rotated Sorted Array":
// What if duplicates are allowed?

// Would this affect the run-time complexity? How and why?
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// The array may contain duplicates.

//还有更好的方法；更复杂的方法，注意分析这道题的复杂度。
class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        int min = num[0];
        for(int i=1; i<n; i++){
        	if(num[i] < min)
        		min = num[i];
        } 
        return min;
    }
};