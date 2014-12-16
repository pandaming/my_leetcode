// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.

class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        vector<string> vec;
        vec.push_back("1");
        for(int i=1;i<n; i++){
            string tmp = vec.back();
            int count;
            char val;
            string s;
            for(int j=0; j<tmp.size(); j++){
                if(j==0){
                    val = tmp[j];
                    count = 1;
                    continue;
                }
                if( tmp[j] == val){
                    count++;
                }else{
                    
                    s.push_back(count+'0');
                    s.push_back(val);
                    count = 1;
                    val = tmp[j];
                }
            }
            s.push_back(count+'0'); 
            s.push_back(val);
            vec.push_back(s);
        }
        return vec[n-1];
    }
};