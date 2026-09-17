class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        // left and right wala is bianry tree and if we want to store n-ary tree
        // then we can do one thing for sure that store the tree in adj list
        int n = nums.size();
        vector<vector<int>> child(n);
        for (int i = 1; i < n; i++) {
            child[parent[i]].push_back(i);
        }
        vector<int> depth(n, 0);
        queue<int> q;
        q.push(0);
        depth[0] = 1;
        int h = 1;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for (int cand : child[temp]) {
                depth[cand] = depth[temp] + 1;
                h = max(h, depth[cand]);
                q.push(cand);
            }
        }
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += (long long)nums[i] * (h - depth[i] + 1);
        }

        return totalSum;
    }
};