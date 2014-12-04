// Given a sorted array of integers, find the starting and ending position 
// of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int beg = 0, end = n -1;
        vector<int> vec;
        while(beg <= end){
            int mid = (beg + end)/2;
            if(A[mid] == target){
                while(mid >= beg){
                    if(A[--mid] != target){
                        break;
                    }
                }
                vec.push_back(++mid);
                while(mid <= end){
                    if(A[++mid] != target){
                        break;
                    }
                }
                vec.push_back(--mid);
                return vec;
            }else if(A[mid] > target){
                end = mid - 1;
            }else{
                beg = mid + 1;
            }
        }
        
        vec.push_back(-1);
        vec.push_back(-1);
        return vec;
    }
};