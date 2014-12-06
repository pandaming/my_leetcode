// Find the contiguous subarray within an array (containing at least one number) 
// which has the largest sum.

// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.

class Solution {
public:
	//用贪婪算法
    int maxSubArray1(int A[], int n) {
        if(n <= 0) return 0;
        int sum = A[0], maxSum = A[0];
        for(int i=1; i<n; i++){
        	if(sum < 0) sum = 0;
        	sum += A[i];
        	maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
    //用动态规划的方法，维护一个local的最大值，和global的最大值；
    int maxSubArray(int A[], int n){
    	int global = A[0];
    	int local = A[0];

    	for(int i=1; i<n; i++){
    		local = max(A[i], local+A[i]);
    		global = max(local, global);
    	}
    	return global;
    }
};