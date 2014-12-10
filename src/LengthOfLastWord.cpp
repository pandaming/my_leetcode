// Given a string s consists of upper/lower-case alphabets 
// and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// For example, 
// Given s = "Hello World",
// return 5.

class Solution {
public:
    int lengthOfLastWord(const char *s) {
     	if(!s || !*s) return 0;

     	int len = 0;
     	int cnt = 0;
     	for(;*s!='\0';s++){
     		if(isalpha(*s)){
     			cnt++;
     		}else{
     			if(cnt>0){
     				len = cnt;
     			}
     			cnt = 0;
     		}
     	}
     	return cnt>0?cnt : len;
    }
};