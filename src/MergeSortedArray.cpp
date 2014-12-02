class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = n+m-1;
        int ia = m-1;
        int ib = n-1;
        for(int i = n+m-1; i>=0;i--){
            if(ia>=0 && ib <0)
                break;
            if(ia<0 && ib>=0){
                A[i] = B[ib--];
                continue;
            }
                
            if(ia >= 0 && ib >= 0){
                if(A[ia] > B[ib]){
                    A[i] = A[ia--];
                }else{
                    A[i] = B[ib--];
                }
            }
        }
    }
};