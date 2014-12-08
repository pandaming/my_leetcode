// Given a collection of candidate numbers (C) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.

// Each number in C may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
// A solution set is: 
// [1, 7] 
// [1, 2, 5] 
// [2, 6] 
// [1, 1, 6] 
// just for github test!
// for the second test!

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int n = num.size();
        vector<vector<int> > result;
        vector<int> solution;
        if(n == 0) return result;

        sort(num.begin(), num.end());
        combinationSumHelper(num, 0, target, solution, result);
        return result;
        
    }

    void combinationSumHelper(vector<int> &num, int start, int target, vector<int> solution, vector<vector<int> > &result){
    	if(target < 0)
    		return;
    	if(target == 0)
    		result.push_back(solution);
    	for(int i=start; i<num.size(); i++){
    		if(i>start && num[i] == num[i-1]) continue;
    		solution.push_back(num[i]);
    		combinationSumHelper(num, i+1, target-num[i], solution, result);
    		solution.pop_back();
    	}
    }

};