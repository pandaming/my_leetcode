// Given n non-negative integers representing an elevation map
// where the width of each bar is 1, compute how much water 
// it is able to trap after raining.

// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
// In this case, 6 units of rain water (blue section) are being trapped. 
// Thanks Marcos for contributing this image!

//找到最高的木板，然后两边向中间逼近。
class Solution {
public:
    int trap(int A[], int n) {
        int highestPos = 0;
        for(int i=0; i<n; i++){
        	if(A[i] > A[highestPos])
        		highestPos = i;
        }


        int count = 0;
        int max = A[0];
        for(int i=1; i<highestPos; i++){
        	if(A[i] > max){
        		max = A[i];
        	}else{
        		count += max-A[i];
        	}
        }

        max = A[n-1];
        for(int i=n-2; i>highestPos; i--){
        	if(A[i] > max){
        		max = A[i];
        	}else{
        		count += max-A[i];
        	}
        }
        return count;
    }
};