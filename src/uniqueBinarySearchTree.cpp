class Solution{
public:
	int numTrees(int n){
		int *a = (int *)malloc((n+1)*sizeof(int));
		memset(a,0,(n+1)*sizeof(int));
		a[0] = 1;
		a[1] = 1;
		for(int i=2; i<=n; i++){
			for(int j=0; j<i; j++){
				a[i] += a[j]*a[i-j-1];
			}
		}
		return a[n];
	}
};