class Solution {
public:
    int atoi(const char *str) {
        if(str == NULL || *str == '\0') return 0;

        for(;isspace(*str);str++);

        int num = 0;

    	bool neg = false;
    	if(*str == '-' || *str == '+'){
    		neg = (*str == '-');
    		str++;
    	}

    	for(; isdigit(*str); str++){
    		int digit = *str - '0';

    		if(neg){
    			if(-num < (INT_MIN + digit)/10){
    				return INT_MIN;
    			}
    		}else{
    			if(num >(INT_MAX - digit)/10){
    				return INT_MAX;
    			}
    		}
    		num = num * 10 + digit;
    	}
    	return neg? -num: num;
    }
};