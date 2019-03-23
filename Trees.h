//掌握树的递归思路：
//总是比较三个东西：根、左子树、右子树；
//定义好对根的操作，然后对左右进行相同的操作
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        else if((root -> left == nullptr) && (root -> right == nullptr)) 
            return (root -> val == sum)? true: false;
        else return (hasPathSum(root->left, sum - (root -> val)) || 
                     hasPathSum(root->right, sum - (root -> val)));
        
    }
};
