// Given a m x n grid filled with non-negative numbers, 
// find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size();
        if(!row) return 0;
        int col = grid[0].size();

        for(int i=1; i<col; i++){
        	grid[0][i] += grid[0][i-1];
        }
        for(int i=1; i<row; i++){
        	grid[i][0] += grid[i-1][0];
        }

        for(int i=1; i<row; i++){
        	for(int j=1; j<col; j++){
        		if(grid[i-1][j] > grid[i][j-1]){
        			grid[i][j] += grid[i][j-1];
        		}else{
        			grid[i][j] += grid[i-1][j];
        		}
        	}
        }
        return grid[row-1][col-1];
    }
};