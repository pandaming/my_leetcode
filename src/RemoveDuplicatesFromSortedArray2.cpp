// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array A = [1,1,1,2,2,3],

// Your function should return length = 5, and A is now [1,1,2,2,3].

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 0) return 0;
        int count = 1;
        int pos = 0;
        for(int i=0; i<n-1; i++){
            if(A[i] == A[i+1]){
                count++;
                if(count == 2){
                    A[++pos] = A[i];
                }
            }else{
                count = 1;
                A[++pos] = A[i+1];
            }   
        
        }
        return pos+1;
    }
};