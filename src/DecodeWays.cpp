class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0) return 0;
        if(n == 1) return check(s[0]);

        int dp[n];
        memset(dp, 0, n*sizeof(int));
        dp[0] = check(s[0]);
        dp[1] = check(s[0]) * check(s[1]) + check(s[0], s[1]);
        for(int i=2; i<n; i++){
        	if(!isdigit(s[i])) continue;
        	if(check(s[i])){
        		dp[i] = dp[i-1];
        	}
        	if(check(s[i-1], s[i])){
        		dp[i] += dp[i-2];
        	}
        }
        return dp[n-1];
    }
    int check(char ch){
    	return (!isdigit(ch) || ch == '0')? 0:1;
    }

    int check(char ch1, char ch2){
    	return (ch1 == '1' || ch1 == '2' && ch2 <= '6')? 1 : 0;
    }
};