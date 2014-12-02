class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int head = 0, last = n - 1;
        while(head <= last){
            if(A[head] == elem){
                A[head] = A[last];
                last--;
                continue;    //resure the changed num is not elem;
            }
            head++;
        }
        return last+1;
    }
};