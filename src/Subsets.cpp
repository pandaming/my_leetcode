// Given a set of distinct integers, S, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
       	int n = S.size();
       	int m = (1<<n)-1;
       	for(int i=0; i<=m; i++){
       		vector<int> vec;
       		for(int j=0; j<n; j++){
       			if(i & (1<<j)){
       				vec.push_back(S[j]);
       			}
       		}
       		result.push_back(vec);
       	}
       	return result;
    }
};