/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int max_root_;
public:
    int maxPathSum(TreeNode* root) {
        max_root_ =  INT_MIN;
        int tmp = helper(root);
        return max_root_;        
    }
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        int max_left = max(0, helper(root->left));
        int max_right = max(0, helper(root->right));
        max_root_ = max(max_root_, max_left + max_right + root->val);
        return root->val + max(max_left, max_right);
    }
};