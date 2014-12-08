// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. 
// If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.


class Solution{
public:
	int search1(int a[], int n, int target){
		int left = 0, right = n - 1;
		while(left <= right){
			int mid = (left + right)/2;
			if(a[mid] = target){
				return true;
			}
			if(IsPossible(a[left], a[mid], target)){
				right = mid - 1;
			}else{
				left = mid + 1;
			}
		}
		return -1;
	}

	bool IsPossible(int start, int end, int target){
		if(start == target || end == target ) return true;
		if(start < end){
			return (target > start &&  target < end);
		}else if(start > end){
			return (target > start || target < end);
		}else{
			return false;
		}
	}

	//第二种方法：
	int search2(int a[], int n, int target){
		
	}
};



