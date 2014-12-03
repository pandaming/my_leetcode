// Given a triangle, find the minimum path sum from top to bottom. 
// Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).



class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle){
		if(triangle.size() == 0) return 0;
		vector<int> vec(triangle[triangle.size()-1]);

		for(int i = triangle.size()-2; i>=0; i--){
			int innerLen = triangle[i].size();
			for(int j=0; j<innerLen; j++){
				int num1 = triangle[i][j] + vec[j];
				int num2 = triangle[i][j] + vec[j+1];
				vec[j] = (num1 < num2)? num1 : num2;
			}
			vec.pop_back();
		}

		int min = INT_MAX;
		for(int i=0; i<vec.size(); i++){
			min = (min<vec[i])? min:vec[i];
		}
		return min;
	}
};