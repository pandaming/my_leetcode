// Given an array of strings, return all groups of strings that are anagrams.

// Note: All inputs will be in lower-case.

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;

        //how to build a hash table;
        map<string, string> m;
        for(int i=0; i<strs.size(); i++){
        	string s = strs[i];
        	sort(s.begin(), s.end());
        	if(m.find(s) == m.end()){
        		m[s] = strs[i];
        	}else{
        		//如何在找到第二个时，使一个anagrams输出；
        		if(m[s] != "#"){
        			result.push_back(m[s]);
        			m[s] = "#";
        		}
        		result.push_back(strs[i]);
        	}

        }
        return result;
    }
};