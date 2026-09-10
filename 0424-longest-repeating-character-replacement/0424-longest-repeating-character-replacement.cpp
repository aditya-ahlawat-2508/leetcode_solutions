class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26, 0);
        int maxf = 0;
        int n = (int)s.size();
        int count = 0;
        int l=0;
        int r=0;

        while (r < n) {
            v[s[r] - 'A']++;
            maxf = *max_element(v.begin(), v.end());
            if ((r - l + 1) - maxf > k) {
                v[s[l] - 'A']--;
                maxf = *max_element(v.begin(), v.end());
                l++;
            }
            if ((r - l + 1) - maxf <= k) count = max(count, r - l + 1);
            r++;
        }
        return count;
    }
};