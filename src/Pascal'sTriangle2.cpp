// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?



//用层层迭代的方法，减少对内存的占用，从后往前迭代，
//与pascal triangle中的res[i] = res[i]+res[i-1]相同的迭代。

class Solution{
public:
	vector<int> getRow(int rowIndex){
		vector<int> result;
		if(rowIndex < 0) return result;
		result.push_back(1);
		for(int i=1; i<=rowIndex; i++){
			result.push_back(1);
			for(int j=i-1; j>0; j--){
				result[j] = result[j]+result[j-1];
			}
		}
		return result;
	}
};