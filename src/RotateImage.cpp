// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Follow up:
// Could you do this in-place?

//沿副对角线对折，然后上下交换位置；
class Solution {
public:
    void rotate(vector<vector<int> > &matrix){
        int row = matrix.size();
        if(row == 0) return;
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
        	for(int j=0; j<row-i-1; j++){
        		int tmp = matrix[i][j];
        		matrix[i][j] = matrix[col-j-1][row-i-1];
        		matrix[col-j-1][row-i-1] = tmp;
        	}
        }

        for(int i=0; i<row/2; i++){
        	for(int j=0; j<col; j++){
        		int tmp = matrix[i][j];
        		matrix[i][j] = matrix[row-i-1][j];
        		matrix[row-i-1][j] = tmp;
        	}
        }

    }
};