// Given a binary tree, flatten it to a linked list in-place.

// For example,
// Given

//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6
// click to show hints.

// Hints:
// If you notice carefully in the flattened tree, each node's
//  right child points to the next node of a pre-order traversal.

class Solution{
public:
    void flatten(TreeNode *root){
      if(root == NULL) return;
      vector<TreeNode *> vec, stack;

      stack.push_back(root);
      while(stack.size() > 0){
          TreeNode *node = stack.back();
          stack.pop_back();
          vec.push_back(node);
          if(node->right)
            stack.push_back(node->right);
          if(node->left)
            stack.push_back(node->left);
      }

      vec.push_back(NULL);
      for(int i=0; i<vec.size()-1; i++){
          vec[i]->right = vec[i+1];
          vec[i]->left = NULL;
      }
  }
};









