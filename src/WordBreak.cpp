// Given a string s and a dictionary of words dict, 
// determine if s can be segmented into a space-separated sequence of one or more dictionary words.

// For example, given
// s = "leetcode",
// dict = ["leet", "code"].

// Return true because "leetcode" can be segmented as "leet code".


//Time Limit Exceeded
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.size() == 0){
        	return true;
        }
        for(int i=1,i<s.size(); i++){
        	string word = s.substr(0,i);
        	if(dict.find(s) != dict.end() && wordBreak(s.substr(i), dict)){
        		return true;
        	}
        }
        return false;
    }
};



//second way
class Solution {
public:
bool wordBreak(string s, unordered_set<string> &dict){
	vector<bool> v(s.size(), false);

	for(int i=0; i<s.size(); i++){
		string w = s.substr(0,i+1);
		
		v[i] = (dict.find(w) != dict.end());
		if(v[i]) continue;

		for(int j=0; j<i; j++){
			if(v[j] == true){
				string tmp = s.substr(j+1, i-j);
				v[i] = (dict.find(tmp) != dict.end());
				if(v[i]) break;
			}
		}
	}
	return v.size()?v[v.size()-1]:true;
}
};




