/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* func(vector<int>& preorder, int& i, int& mini, int &maxi) {
        if (i >= preorder.size() || preorder[i] > maxi || preorder[i]<mini) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = func(preorder, i, mini, root->val);
        root->right = func(preorder, i, root->val, maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // after making the tree we haave to return the root
        int maxi = INT_MAX;
        int mini=INT_MIN;
        int i = 0;

        return func(preorder, i, mini ,maxi);
    }
};