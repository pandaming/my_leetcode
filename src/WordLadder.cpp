class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> Q;
        Q.push(start);
        int cnt = 1;

        while(Q.empty() == false){
        	string str = Q.front();
        	Q.pop();
        	if(str != ""){
        		for(int i=0; i<str.length; i++){
	        		char tmp = str[i];
	        		for(char c='a'; c<='z';c++){
	        			if (c == tmp) continue;
	        			str[i] = c;
	        			if(str == end) return cnt + 1;
	        			if(dict.find(str) != dict.end()){
	        				Q.push(str);
	        			} 
	        		}
	        		str[i] = tmp;
	        	}
        	}
        	if(Q.empty() == false){
        		cnt++;
        		Q.push("");
        	}
        	
        }
        return 0;
    }
};