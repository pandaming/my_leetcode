// A peak element is an element that is greater than its neighbors.

// Given an input array where num[i] ≠ num[i+1], 
// find a peak element and return its index.

// The array may contain multiple peaks, 
// in that case return the index to any one of the peaks is fine.

// You may imagine that num[-1] = num[n] = -∞.

// For example, in array [1, 2, 3, 1], 3 is a peak element 
// and your function should return the index number 2.

// click to show spoilers.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

//用非递归的方法
class Solution1 {
public:
    int findPeakElement(const vector<int> &num){
        int n = num.size();
        int left = 0, right = n-1;
        while(left < right){
        	int mid = (left+right)/2;
        	if(right-left == 1) return num[left]>num[right]?left:right;//用来处理边界边界条件
        	if(num[mid] > num[mid-1] && num[mid] > num[mid+1]){
        		return mid;
        	}
        	else if(num[mid] < num[mid-1]){
        		right = mid - 1;
        	}else{
        		left = mid + 1;
        	}
        }
        return left;
    }
};




//用递归的方法：
class Solution1 {
public:
    int findPeakElement(const vector<int> &num){
    	return findPeakHelper(num, 0, num.size()-1);
    }

    int findPeakHelper(const vector<int> &num, int start, int end){
    	if(start == end) return start;
    	if(end - start == 1) return num[start]>num[end]?start:end;
    	int mid = (start + end)/2;
    	if(num[mid] > num[mid-1] && num[mid] > num[mid+1]) {
    		return mid;
    	}
    	else if(num[mid] < num[mid-1]) {
    		return findPeakHelper(num, start, mid-1);
    	}
    	else{
    		return findPeakHelper(num, mid+1, end);
    	}
    }
};



