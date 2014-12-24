class Solution {
public:
    int singleNumber(int A[], int n) {
        int result;
        for(int i=0; i<n; i++){
        	result = result ^ A[i];
        }
        return result;
    }
};