//two way 
//用暴力枚举的方法来做o(n2)
//时间超时！！~~~~
class Solution {
public:
    vector<int> twoSum1(vector<int> &numbers, int target){
		vector<int> result;
		for(int i=0; i<numbers.size()-1; i++){
			int tmp = target - numbers[i];
			for(int j=i+1; j< numbers.size(); j++){
				if(numbers[j] == tmp){
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;	
	}

	//第二种方法利用hash来做，可以减少时间复杂度；
	vector<int> twoSum(vector<int> &numbers, int target){
		map<int, int> m;
		vector<int> result;
		for(int i=0; i<numbers.size(); i++){
			if(m.find(numbers[i]) == m.end()){
				m[target - numbers[i]] = i;
				continue;
			}
			result.push_back(m[numbers[i]]);
			result.push_back(i);
		}
		return result;
	}
};