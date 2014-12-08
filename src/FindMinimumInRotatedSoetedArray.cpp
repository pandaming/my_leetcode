// Suppose a sorted array is rotated at some pivot
 // unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// You may assume no duplicate exists in the array.
// add comment
class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        int start = 0;
        int end = n - 1;
        while(start < end){
        	int mid = (start + end)/2;
        	if(num[mid] > num[end]){
        		start = mid + 1;
        	}else{
        		end = mid;  //防止中间情况出现
        	}
        }
        return num[start];
    }
};