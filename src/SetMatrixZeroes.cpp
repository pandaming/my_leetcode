// Given a m x n matrix, if an element is 0, 
// set its entire row and column to 0. Do it in place.

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int bRow = false, bCol = false;

        for(int r=0; r<matrix.size(); r++){
        	for(int c=0; c<matrix[r].size();c++){
        		if(matrix[r][c] == 0){
        			if(r == 0) bRow = true;
        			if(c == 0) bCol = true;
        			matrix[0][c] = matrix[0][r] = 0;
        		}
        	}
        }
        for(int r=1; r<matrix.size(); r++){
        	for(int c=1; c<matrix[r].size();c++){
        		if(matrix[0][c] == 0 || matrix[r][0] == 0){
        			matrix[r][c] = 0;
        		}
        	}
        }
        if(bRow){
        	for(int c=0; c<matrix[0].size(); c++) matrix[0][c] = 0;
        }
    	if(bCol){
    		for(int r=0; r<matrix.size(); r++) matrix[r][0] = 0;
    	}
    }
};