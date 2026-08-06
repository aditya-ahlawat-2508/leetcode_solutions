class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        if (groupSize == 1) return true;

        sort(hand.begin(), hand.end());

        unordered_map<int, int> cnt;
        for (int x : hand) cnt[x]++;

        for (int x : hand) {
            if (cnt[x] == 0) continue;        // already eaten by an earlier group
            for (int k = 0; k < groupSize; k++) {
                if (cnt[x + k] == 0) return false;
                cnt[x + k]--;
            }
        }
        return true;
    }
};