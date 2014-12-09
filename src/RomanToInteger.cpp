// Given a roman numeral, convert it to an integer.

// Input is guaranteed to be within the range from 1 to 3999.
//将string数组转化为int
class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        if(s.size() == 0) return num;
        for(int i=0; i<s.size(); i++){
        	num = num * 10 + (s[i] - '0');
        }
        return num;
    }
};

class Solution {  
public:  
    int romanToInt(string s) {  
        // Note: The Solution object is instantiated only once and is reused by each test case.  
        int result=0;  
          
        map<char,int> roman;  
        roman['I']=1;  
        roman['V']=5;  
        roman['X']=10;  
        roman['L']=50;  
        roman['C']=100;  
        roman['D']=500;  
        roman['M']=1000;  
          
        for(int i=s.length()-1;i>=0;i--)  
        {  
            if(i==s.length()-1)  
            {  
                result=roman[s[i]];  
                continue;  
            }  
            if(roman[s[i]] >= roman[s[i+1]])  
                result+=roman[s[i]];  
            else  
                result-=roman[s[i]];  
        }  
        return result;  
    }  
};