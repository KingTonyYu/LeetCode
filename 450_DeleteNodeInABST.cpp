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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key == root->val) {
            if (!root->left && !root->right)
                return nullptr;
            else if (!root->right)
                return root->left;
            else if (!root->left)
                return root->right;
            else {
                TreeNode* tmp = findMin(root->right);
                root->val = tmp->val;
                root->right = deleteNode(root->right, tmp->val);
            }
        }
        else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    TreeNode* findMin(TreeNode* root) {
        if (!root->left)
            return root;
        return findMin(root->left);
    }
};