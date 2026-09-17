class Solution {
    priority_queue<int> q;

public:
    int dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            q.push(1);
            return 1;
        }
        int lh = (root->left != nullptr) ? dfs(root->left) : 0;
        int rh = (root->right != nullptr) ? dfs(root->right) : 0;

        if (lh == -1 || rh == -1 || lh != rh) {
            return -1;
        }
        q.push(1 + lh + rh);
        return 1 + lh + rh;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        while (k > 1 && !q.empty()) {
            k--;
            q.pop();
        }
        if (q.empty())
            return -1;
        return q.top();
    }
};