// Given an array with n objects colored red, white or blue, 
// sort them so that objects of the same color are adjacent, 
// with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, 
// white, and blue respectively.


class Solution {
public:
    void sortColors(int A[], int n) {
    	if(n <= 1) return;
    	int pos0 = 0;
    	int pos2 = n - 1;
    	int cur = 0;
    	while(cur <= pos2){
    		if(A[cur] == 0){
    			if(cur > i){
    				swap(A[pos0++], A[cur]);
    			}else{
    				cur++;
    				i++;

    			}
    		}else if(A[cur] == 2){
    			swap(A[pos2--],A[cur]);
    		}else{
    			cur++;
    		}
    	}

    }
};