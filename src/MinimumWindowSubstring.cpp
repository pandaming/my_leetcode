// Given a string S and a string T, 
// find the minimum window in S which will contain all the characters 
// in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, 
// return the emtpy string "".

// If there are multiple such windows, you are guaranteed that 
// there will always be only one unique minimum window in S.

class Solution {
public:
    string minWindow(string S, string T) {
    	string min;
    	if(S.size() <= 0 || T.size() <= 0 || T.size() > S.size()) return min;

    	const int MAX_CHARS = 256;
    	int f[MAX_CHARS], m[MAX_CHARS];

    	const int NOT_EXISTED = -1;
    	const int NOT_FOUND = 0;
    	memset(f, NOT_EXISTED, sizeof(f));
    	memset(m, NOT_EXISTED, sizeof(m));

    	for(int i=0; i<T.size(); i++){
    		m[T[i]] == NOT_EXISTED? m[T[i]] = 1 : m[T[i]]++;
    		f[T[i]] = NOT_FOUND;
    	}    


    	int start = -1;
    	int winSize = INT_MAX;
    	int letterFound = 0;
    	int begin = 0;

    	for(int i=0; i<S.size(); i++){
    		if(m[S[i]]!= NOT_EXISTED){
    			char ch = S[i];
    			f[ch]++;
    			if(f[ch]<= m[ch]){
    				letterFound++;
    			}
    			if(letterFound >= T.size()){
    				while(f[S[begin]] == NOT_FOUND || f[S[begin]] > m[S[begin]]){
    					if(f[S[begin]] > m[S[begin]]){
    						f[S[begin]]--;
    					}
    					begin++;
    				}
    				if(winSize > i-begin+1){
    					start = begin;
    					winSize = i-begin+1;
    				}
    			}

    		}
    	}
    	if(start >=0 && winSize >0){
    		win = S.substr(start, winSize);
    	}
    	return win;
    }
};





