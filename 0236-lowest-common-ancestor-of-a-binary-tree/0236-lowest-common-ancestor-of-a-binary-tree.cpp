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
    TreeNode* h(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = h(root->left, p, q);
        TreeNode* right = h(root->right, p, q);
        if (left != nullptr && right != nullptr)
            return root;
        else if (left == nullptr && right == nullptr) {
            return nullptr;
        } else if (left == nullptr && right != nullptr) {
            return right;
        } else
            return left;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        return h(root, p, q);
    }
};