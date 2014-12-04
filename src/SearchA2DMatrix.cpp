// Write an efficient algorithm that searches for a value in an m x n matrix. 
// This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,

// Consider the following matrix:

// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();
        int up = 0, down = row-1;
        while(up <= down){
            int mid = (up + down)/2;
            if(matrix[mid][0] > target){
                down = mid -1;
            }
            else if(matrix[mid][0] < target){
                if(matrix[mid][col-1] >= target){
                    int left = 0, right = col -1;
                    while(left <= right){
                        int mid_row = (left + right)/2;
                        if(matrix[mid][mid_row] == target){
                            return true;
                        }else if(matrix[mid][mid_row] > target){
                            right = mid_row - 1;
                        }else{
                            left = mid_row + 1;
                        }
                    }
                    return false;
                }
                else{
                    up = mid + 1; 
                }
            }
            else{
                return true;
            }
        }
        return false;
    }
};