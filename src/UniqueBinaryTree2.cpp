class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
		return generateTrees(1,n);    
    }

    vector<TreeNode *> generateTrees(int beg, int end){
    	vector<TreeNode *> vec;
    	if(beg > end){
    		vec.push_back(NULL);
    		return vec;
    	}
    	if(beg == end){
    		TreeNode *node = new TreeNode(beg);
    		vec.push_back(node);
    		return vec;
    	}

    	for(int i=beg; i<=end; i++){
    		vector<TreeNode *> vLeft = generateTrees(beg, i-1);
    		vector<TreeNode *> vRight = generateTrees(i+1, end);
    		for(int j=0; j<vLeft.size(); j++){
    			for(int k=0; k<vRight.size(); k++){
    				TreeNode *root = new TreeNode(i);
    				root->left = vLeft[j];
    				root->right = vRight[k];
    				vec.push_back(root);
    			}
    		}
    	}
    	return vec;
    }
};