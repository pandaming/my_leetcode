 //problem time limits;
 int uniquePaths1(int m, int n) {
    if(m == 1 || n == 1) return 1;
    return uniquePaths1(m, n-1)+uniquePaths1(m-1,n);
}

//用杨辉三角来做
//this way is accepted;
int uniquePaths(int m, int n){
	int a[m][n];
	for(int i=0; i<m; i++){
		a[i][0] = 1;
	}
	for(int i=0; i<n; i++){
		a[0][i] = 1;
	}
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			a[i][j] = a[i-1][j] + a[i][j-1];
		}
	}
	return a[m-1][n-1];
}