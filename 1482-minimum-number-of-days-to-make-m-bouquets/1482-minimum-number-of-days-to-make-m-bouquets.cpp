class Solution {
public:
    bool func(vector<int>& bloomDay, int m, int k, int mid) {
        // m==no of bouquet
        // k==no of adjcent flowers

        int count = 0;
        int temp = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                temp++;
            } else {
                // temp is the no of adjcent elements till i-1
                count += temp / k;
                temp = 0;
            }
        }
        count += temp / k;
        return count >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        long long res = m;
        res *= k;
        if (res > bloomDay.size())
            return -1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (func(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};