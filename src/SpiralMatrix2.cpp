// Given an integer n, generate a square matrix filled 
// with elements from 1 to n2 in spiral order.

// For example,
// Given n = 3,

// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
  		vector<vector<int> > result(n, vector<int>(n));
  		int x1 = 0, y1 = 0;
  		int x2 = n-1, y2 = n - 1;
  		for(int k=1; k<=n*n;){
  			for(int j=y1; j<=y2; j++){
  				result[x1][j] = k++;
  			}
  			for(int j=x1+1; j<=x2; j++){
  				result[j][y2] = k++;
  			}
  			for(int j=y2-1; j>=y1; j--){
  				result[x2][j] = k++;
  			}
  			for(int j=x2-1; j>x1; j--){
  				result[j][y1] = k++;
  			}
  			x1++, y1++, x2--, y2--;
  		}
  		return result;
    }
};



