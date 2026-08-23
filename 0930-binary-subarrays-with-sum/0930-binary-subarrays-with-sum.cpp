class Solution {
public:
    int func(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;

        int l = 0;
        int r = 0;
        int sum = 0;
        int count = 0;

        while (r < nums.size()) {
            sum += nums[r];
            while (sum > goal) {
                sum = sum - nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums, goal) - func(nums, goal - 1);
    }
};