// Given a set of candidate numbers (C) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
// (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

void combinationSumHelper(vector<int> &candidates, int start, int target, vector<int> &solution, vector<vector<int> > &result){
	if(target < 0){
		return;
	}
	if(target == 0){
		result.push_back(solution);
	}
	for(int i=start; i<candidates.size(); i++){
		if (i>start && candidates[i] == candidates[i-1]){
            continue;
        }
		solution.push_back(candidates[i]);
		combinationSumHelper(candidates, i, target-candidates[i], solution, result);
		solution.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target){
	vector<vector<int> > result;
	if(candidates.size() == 0) return result;

	//sort the candidates<vec>
	sort(candidates.begin(), candidates.end());

	vector<int> solution;
	combinationSumHelper(candidates, 0, target, solution, result);
	return result;
}



