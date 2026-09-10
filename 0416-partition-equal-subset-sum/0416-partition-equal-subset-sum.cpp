class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int s = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(s + 1, false));
        //  base case
        for (int i = 0; i < n; i++) {
            dp[i][0] = false;
        }
        if (nums[0] <= s) {
            dp[0][nums[0]] = true;
        }
        // dp[index][target]-->
        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= s; target++) {
                bool not_take = dp[i - 1][target];
                bool take = false;
                if (nums[i] <= target) {
                    take = dp[i - 1][target - nums[i]];
                }
                dp[i][target] = take || not_take;
            }
        }

        return dp[n - 1][sum / 2];
    }
};