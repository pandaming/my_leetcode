class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
     	string s;
     	if(strs.size() == 0) return s;
     	if(strs.size() == 1) return strs[0];

     	s = strs[0];

     	for(int i=1; i<strs.size(); i++){
     		string tmp = strs[i];
     		int j=0;
     		int n = min(s.size(), tmp.size());
     		while(j<n){
     			if(s[j] != tmp[j]){
     				break;
     			}
     			j++;
     		}
     		s.erase(j,s.size());
     	}   
     	return s;
    }
};