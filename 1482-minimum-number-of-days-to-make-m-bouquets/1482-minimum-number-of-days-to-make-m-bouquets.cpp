class Solution {
public:
    bool check(vector<int>& bloomDay, int mid, int m, int k) {
        int consequitive = 0;
        int bou = 0;
        for (int p : bloomDay) {
            if (p <= mid) {
                consequitive++;
                if (consequitive == k) {
                    bou++;
                    consequitive = 0;
                }
            } else {
                consequitive =
                    0; // this flower will be bloomed after mid number of days
            }
        }
        return bou >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        long long req = m * 1LL * k;
        int ans = -1;
        if (bloomDay.size() < req)
            return -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};