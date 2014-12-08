// Find the contiguous subarray within an array (containing at least one number) 
// which has the largest product.

// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.

//动态规划，最重要的是要写出其状态转移方程，
//在邱最大乘积的时候，除了维护局部最大值，还要维护局部最小值，因为负数乘以
//负数会的到一个大的正数。


//this is the leetcode's solution
// Let us denote that:

// f(k) = Largest product subarray, from index 0 up to k.
// Similarly,

// g(k) = Smallest product subarray, from index 0 up to k.
// Then,

// f(k) = max( f(k-1) * A[k], A[k], g(k-1) * A[k] )
// g(k) = min( g(k-1) * A[k], A[k], f(k-1) * A[k] )


class Solution {
public:
	//动态规划的方法
    int maxProduct1(int A[], int n) {
       int max_local = A[0];
       int min_local = A[0];

       int global = A[0];
       for(int i=1; i<n; i++){
       		int max_copy = max_local;
       	    max_local = max(max(A[i], A[i]*max_local), min_local*A[i]);
       	    min_local = min(min(A[i], max_copy * A[i]), min_local * A[i]);
       	    global = max(global, max_local);
       }
       return global;
    }
};