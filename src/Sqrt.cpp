class Solution {
public:
    int sqrt(int x) {
        if(x == 0 || x == 1) return x;
        unsigned long long beg = 0;
        unsigned long long end = (x+1)/2;
        unsigned long long mid;
        unsigned long long tmp;
        
        while(beg < end){
            mid = (beg + end)/2;
            tmp = mid * mid;
            if(tmp == x) return mid;
            if(tmp < x){
                beg = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        tmp = end * end;
        if(tmp > x){
            return end - 1;
        }else{
            return end;
        }
    }
};