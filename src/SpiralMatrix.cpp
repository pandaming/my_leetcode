// Given a matrix of m x n elements (m rows, n columns), 
// return all elements of the matrix in spiral order.

// For example,
// Given the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int m = matrix.size();
       	if(m == 0) return result;
       	int n = matrix[0].size();

       	int x1 = 0;
       	int y1 = 0;
       	int x2 = m-1;
       	int y2 = n-1;

       	while(x1 <= x2 && y1 <= y2){
       		//to right 
       		for(int i=y1; i<=y2;i++){
       			result.push_back(matrix[x1][i]);
       		}
       		//to bottom
       		for(int i=x1+1; i<=x2; i++){
       			result.push_back(matrix[i][y2]);
       		}
       		//to left
       		if(x1 != x2){
       		    for(int i=y2-1; i>=y1;i--){
           			result.push_back(matrix[x2][i]);
           		}
       		}
       		//加入判断是为了防止出现单行，单列的情况
       		//to up
       		if(y1 != y2){
       		    for(int i=x2-1; i>x1; i--){
           			result.push_back(matrix[i][y1]);
           		}
       		}
       		
       		x1++,y1++, x2--,y2--;
       	}
       	return result;
    }
};