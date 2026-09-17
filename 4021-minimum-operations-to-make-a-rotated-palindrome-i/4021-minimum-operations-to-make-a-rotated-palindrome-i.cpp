class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int minCost = INT_MAX;

        for (int i = 0; i < n; i++) {
            // s ab current rotation hai
            int l = 0, r = n - 1;
            int cost = 0;
            while (l < r) {
                int diff = abs((s[r] - 'a') - (s[l] - 'a'));
                cost += min(diff, 26 - diff);
                l++;
                r--;
            }
            minCost = min(minCost, i + cost);

            // poori string ko ek jagah left rotate karo (agle iteration ke
            // liye)
            char first = s[0];
            for (int k = 0; k < n - 1; k++) {
                s[k] = s[k + 1];
            }
            s[n - 1] = first;
        }
        return minCost;
    }
    // lowercase english letters
    // perform following ops any no of times including 0 in any order
};