// Implement strStr().

// Returns the index of 
// the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

class Solution {
public:
    int strStr(char *haystack, char *needle) {
    	if(haystack == NULL || needle == NULL) return -1;
    	int len1 = strlen(haystack);
    	int len2 = strlen(needle);
    	if( len2==0) return 0;
    	if(len1==0) return -1;
    	int pos1;
    	int pos2;
    	for(pos1=0, pos2=0; pos1<len1 && pos2<len2;){
    		if(haystack[pos1] == needle[pos2]){
    			pos1++;
    			pos2++;
    		}else{
    			pos1 = pos1-pos2+1;
    			pos2=0;
    		}
    	}
    	return needle[pos2]=='\0'?pos1-pos2:-1 ;
}
};