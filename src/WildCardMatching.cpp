// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

class Solution {
public:
    bool isMatch(const char *s, const char *p){
        const char *p1, *s1;
        bool star = false; //用于控制*
        while(*s && (*p || star)){
        	if(*p == '?' || *s == *p){
        		s++; p++;
        	}else if(*p == '*'){
        		star = true;
        		p++;
        		if(*p == '\0') return true;
        		p1 = p;
        		s1 = s;
        	}else{
        		if(star == false) return false;
        		p = p1;
        		//代码真他妈的写得好！~
        		s = ++s1;
        	}
        }
        if(*s == '\0'){
            while(*p == '*') p++;
        	if(*p == '\0') return true;
        }
        return false;
    }
};

