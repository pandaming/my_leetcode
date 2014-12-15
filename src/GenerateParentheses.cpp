// Given n pairs of parentheses, write a function to 
// generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> result; 
    	string s;
    	genertor(result, n, n, s);
    	return result;
    }

    void genertor(vector<string> &result, int left, int right, string s){
    	if(left == 0 && rignt == 0){
    		result.push_back(s);
    		return;
    	}
    	if(left > 0){
    		genertor(result, left-1, right, s+'(');
    	}
    	if(right>0 && right > left){
    		genertor(reault, left, right-1, s+')');
    	}
    }
};