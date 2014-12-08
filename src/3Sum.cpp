class Solution {
public:
 vector<vector<int> > threeSum(vector<int> &num) {

    	vector<vector<int> > result;
    	if(num.size() < 3) return result;
    	//sort the array, to build the yang's matrix;
    	sort(num.begin(), num.end());

    	for(int i=0; i<num.size()-2; i++){
    		if(i>0 && num[i-1] == num[i]) continue;
    		int tmp = num[i];
    		int left = i+1;
    		int right = num.size()-1;
    		while(left < right){
    			if(num[left] + num[right] + tmp > 0){
    			    while(right>0 && num[right] == num[right-1]) right--;
    				right--;
    			}else if(num[left] + num[right] + tmp < 0){
    			    while(left<num.size() && num[left] == num[left+1]) left++;
    				left++;
    			}else{
    			    vector<int> solution;
    			    solution.push_back(tmp);
    				solution.push_back(num[left]);
    				solution.push_back(num[right]);
    				result.push_back(solution);
    				while(right>0 && num[right] == num[right-1]) right--;
    		        while(left<num.size() && num[left] == num[left+1]) left++;
    				left++;
    				right--;
    			}
    		}
    	}
        return result;
    }
};