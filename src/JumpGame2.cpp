// Given an array of non-negative integers, you are initially positioned 
// at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// For example:
// Given array A = [2,3,1,1,4]

// The minimum number of jumps to reach the last index is 2. 
// (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

class Solution {
public:
	//用动态规划的方法
    int jump(int A[], int n) {
       if(n <= 0) return 0;
       int dp[n];
       dp[0] = 0;
       for(int i=1; i<n; i++){
       		dp[i] = INT_MAX;
       }

       for(int i=1; i<n; i++){
       		for(int j=0; j<i; j++){
       			if(A[j]+j >= i){
       				int tmp = dp[j] + 1;
       				if(tmp < dp[i]){
       					dp[i] = tmp;
       					break;
       				}
       			}
       		}
       }
       return dp[n-1];
    }
};