// Given an array of non-negative integers, 
// you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// For example:
// A = [2,3,1,1,4], return true.

// A = [3,2,1,0,4], return false.


class Solution {
public:
	//time limit out
    bool canJump1(int A[], int n) {
        bool canVisit[n];
       	canVisit[n-1] = true;
       	for(int i=n-2; i>=0; i--){
       		int cnt = A[i];
       		canVisit[i] = false;
       		for(int j=1; j+i<n && j<=cnt; j++){
       			if(canVisit[i+j] == true){
       				canVisit[i] = ture;
   					break;
       			}
       		}

       	}
       	return canVisit[0];
    }


    //solution2
    bool canJump(int A[], int n){
    	if(n <= 0) return false;

    	int cover = 0;
    	for(int i=0; i<=cover && i<n; i++){
    		if(cover < A[i] + i){
    			cover = A[i] + i;
    		}

    		if(cover >= n-1){
    			return true;
    		}
    	}
    	return false;
    }





};