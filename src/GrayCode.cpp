class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> num;
        int size = 1<<n;
        for(int i=0; i<size; i++){
        	int gCode = i ^ i>>1;
        	num.push_back(gCode);
        }
        return num;
    }
};