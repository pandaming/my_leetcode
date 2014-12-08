// Given an array S of n integers, are there elements a, b, c, 
// and d in S such that a + b + c + d = target? Find all unique quadruplets 
// in the array which gives the sum of target.

// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
// (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
//     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

//     A solution set is:
//     (-1,  0, 0, 1)
//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)


class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if(num.size()<4) return result;

        sort(num.begin(), num.end());

        int n = num.size();
        for(int i=0; i<n-3; i++){
        	if(i>0 && num[i] == num[i-1]) continue;
        	for(int j=i+1; j<n; j++){
        	    if(j >i+1 && num[j] == num[j-1]) continue;
        		int a = num[i];
        		int b = num[j];

        		int left = j + 1;
        		int right = n - 1;
        		
        		while(left < right){
        		    int sum = a + b + num[left] + num[right];
        			if(sum == target){
        				vector<int> v;
        				v.push_back(a);
        				v.push_back(b);
        				v.push_back(num[left]);
        				v.push_back(num[right]);
        				result.push_back(v);
        				while(left<n && num[left] == num[left+1]) left++;
        				while(right>0 && num[right] == num[right-1]) right--;
        				left++;
        				right--;
        			}else if(sum > target){
        				while(right>0 && num[right] == num[right-1]) right--;
        				right--;
        			}else{
        				while(left<n && num[left] == num[left+1]) left++;
        				left++;
        			}
        		}
        	}
        }
        return result;
    }
};