// Follow up for "Unique Paths":

// Now consider if some obstacles are added to the grids. 
// How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.

// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.

// Note: m and n will be at most 100.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int a[m][n];

        bool flag = true;
        for(int i=0; i<m; i++){
        	if(flag){
        		if(obstacleGrid[i][0] != 1){
        			a[i][0] = 1;
        		}else{
        			a[i][0] = 0;
        			flag = false;
        		}
        	}else{
        		a[i][0] = 0;
            }
        }
        
        flag = true;
        for(int i=0; i<n; i++){
            if(flag){
                if(obstacleGrid[0][i] != 1){
                    a[0][i] = 1;
                }else{
                    a[0][i] = 0;
                    flag = false;
                }
            }else{
                a[0][i] = 0;
            }
        }
            
        for(int i=1;i<m;i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    a[i][j] = 0;
                }else{
                    a[i][j] = a[i-1][j] + a[i][j-1];
                }
            }
        }
        
        return a[m-1][n-1];
    }
};