// 容积即面积，它受长和高的影响，
// 当长度减小时候，高必须增长才有可能提升面积，
// 所以我们从长度最长时开始递减，然后寻找更高的线来更新候补；

class Solution {
public:
    int maxArea(vector<int> &height) {
        if(height.size() == 0) return 0;
        int left = 0;
        int right = height.size() - 1;
        int maxContainer = 0;
        while(left < right){
        	maxContainer = max(maxContainer, min(height[left], height[right])*(right-left));
        	if(height[left] < height[right]){
        		int k = left;
        		while(left<right && height[k] <= height[left])
        			k++;
        		left = k;
        	}else{
        		int k = right;
        		while(right > left && height[k]<=height[right])
        			k--;
        		right = k;
        	}
        }
        return maxContainer;
    }
};