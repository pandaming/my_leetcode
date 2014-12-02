class Solution{
public:
	TreeNode *sortedArrayToBST(vector<int> &num){
		if(num.size() == 0){
			return NULL;
		}
		if(num.size() == 1){
			return new TreeNode(num[0]);
		}

		int mid = num.size()/2;

		TreeNode *node = new TreeNode(num[mid]);

		vector<int>::const_iterator first;
		vector<int>::const_iterator last;

		first = num.cbegin();
		last = num.cbegin() + mid;

		vector<int> vec(first, last);
		node->left = sortedArrayToBST(vec);

		if(mid == num.size()-1){
			node->right = NULL;
		}else{
			first = num.begin()+mid+1;
			last = num.end();
			vector<int> vec(first, last);
			node-right = sortedArrayToBST(vec)
		}
		
	}
}