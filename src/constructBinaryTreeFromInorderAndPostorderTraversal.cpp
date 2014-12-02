TreeNode * buildTree(vector<int> &inorder, int in_offset, vector<int> &postorder, int post_offset, int n){
	if(n == 0 || postorder.size() == 0 || inorder.size() == 0) return NULL;
	int root_num = postorder[post_offset+n-1];
	TreeNode *root = new TreeNode(root_num);

	if(n == 1) return root;

	int pos;
	for(pos=in_offset; pos<in_offset+n; pos++){
		if(inorder[pos] == root_num)
			break;
	}

	int left_n = pos - in_offset;
	int right_n = in_offset + n - pos -1;
	
	root->left = buildTree1(inorder, in_offset, postorder, post_offset, left_n);    
    root->right = buildTree1(inorder, pos+1, postorder, post_offset+left_n ,right_n);
    return root;
}