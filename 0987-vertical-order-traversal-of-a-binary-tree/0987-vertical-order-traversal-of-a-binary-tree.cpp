class Solution {
public:
    void find(TreeNode* root, int& l, int& r, int pos) {
        if (!root) return;

        l = min(l, pos);
        r = max(r, pos);

        find(root->left, l, r, pos - 1);
        find(root->right, l, r, pos + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        int l = 0, r = 0;
        find(root, l, r, 0);

        vector<vector<int>> ans(r - l + 1);

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            vector<pair<int, int>> v;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                int col = q.front().second;
                q.pop();

                v.push_back({col, node->val});

                if (node->left)
                    q.push({node->left, col - 1});

                if (node->right)
                    q.push({node->right, col + 1});
            }

            sort(v.begin(), v.end());

            for (int i = 0; i < v.size(); i++) {
                ans[abs(l) + v[i].first].push_back(v[i].second);
            }
        }

        return ans;
    }
};