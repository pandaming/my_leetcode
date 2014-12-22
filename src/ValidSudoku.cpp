class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int row[9], col[9];

        for(int i=0; i<9; i++){
        	memset(row, 0, 9*sizeof(int));
        	memset(col, 0, 9*sizeof(int));
        	for(int j=0; j<9; j++){
        		if(board[i][j] != '.'){
        			if(row[board[i][j]-'1'] > 0) return false;
        			else row[board[i][j]-'1']++;
        		}
        		if(board[j][i] != '.'){
        			if(col[board[j][i]-'1'] > 0) return false;
        			else col[board[j][i]-'1']++;
        		}
        	}
        }

        for(int i=0; i<9; i+=3){
        	for(int j=0; j<9; j+=3){
        		memset(row, 0, 9*sizeof(int));
        		for(int a=0; a<3; a++){
        			for(int b=0; b<3; b++){
        				if(board[i+a][j+b] != '.'){
        					if(row[board[i+a][j+b]-'1'] > 0) return false;
        					else row[board[i+a][j+b]-'1']++;
        				}
        			}
        		}
        	}
        }
        return true;
    }
};