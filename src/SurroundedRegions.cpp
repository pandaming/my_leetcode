// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X

struct position{
	int row, col;
	void set(int r, int c){
		row = r; 
		col = c;
	}
	position(int r, int c):row(r), col(c){}
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
    	if(board.size() <=0 || board[0].size() <=0) return;
        int row = board.size();
        int col = board[0].size();

        queue<position> q;
        position p(0,0);

        for(int i=0; i<row; i++){
        	if(board[i][0] == 'O'){
        		board[i][0] = 'N';
        		p.set(i,0);
        		q.push(p);
        	}
        	if(board[i][col-1] == 'O'){
        		board[i][col-1] = 'N';
        		p.set(i, col-1);
        		q.push(p);
        	}
        }


        for(int i=1; i<col-1; i++){
        	if(board[0][i] == 'O'){
	        	board[0][i] = 'N';
	            p.set(0, i);
	            q.push(p); 
	        }
	        if ( board[row-1][i] == 'O') {
	            board[row-1][i] = 'N';
	            p.set(row-1, i);
	            q.push(p); 
	        }
        }

        while(!q.empty()){
        	p = q.front();
        	q.pop();
        	int r = p.row;
        	int c = p.col;
        	if(r < row-1 && board[r+1][c] == 'O'){
				board[r+1][c] = 'N';
	            p.set(r+1, c);
	            q.push(p); 
        	}
        	if(r > 0 && board[r-1][c] == 'O'){
        		board[r-1][c] = 'N';
        		p.set(r-1, c);
        		q.push(p);
        	}
        	if(c < col-1 && board[r][c+1] == 'O'){
        		board[r][c+1] = 'N';
        		p.set(r, c+1);
        		q.push(p);
        	}
        	if(c > 0 && board[r][c-1] == 'O'){
        		board[r][c-1] = 'N';
        		p.set(r, c-1);
        		q.push(p);
        	}
        }
        //loop the vector, change the N to O;
        for(int i=0; i<row; i++){
        	for(int j=0; j<col; j++){
        		if(board[i][j] == 'O'){
        			board[i][j] == 'X';
        		}else if(board[i][j] == 'N'){
        			board[i][j] == 'O';
        		}
        	}
        }
    }
};