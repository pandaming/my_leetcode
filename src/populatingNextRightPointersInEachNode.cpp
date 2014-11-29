
// Given a binary tree

//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Note:

// You may only use constant extra space.
// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
// For example,
// Given the following perfect binary tree,
//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL


struct TreeLinkNode{
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
};

class Solution{
public:
	void connect(TreeLinkNode *root){
		if(root == NULL) return NULL;
		vector<TreeLinkNode *> stack1;
		vector<TreeLinkNode* > stack2;

		stack1.push_back(root);
		while(stack1.size() > 0){
			while(stack1.size() > 0){
				TreeLinkNode *node = stack1.back();
				stack1.pop_back();
				if(node->right)
					stack2.push_back(node->right);
				if(node->left)
					stack2.push_back(node->left;)
			}

			TreeLinkNode *left_node = stack2.back();
			stack2.pop_back();
			stack1.push_back(left_node);
			while(stack2.size() > 0){
				TreeLinkNode *right_node = stack2.back();
				stack2.pop_back();
				stack1.push_back(right_node);
				left_node->next = right_node;
				left_node = right_node;
			}
			left_node->next = NULL;
		}
	}
};



