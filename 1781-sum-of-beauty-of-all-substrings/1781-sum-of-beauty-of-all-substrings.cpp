class Solution {
public:
    int beautySum(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mpp;
            for (int j = i; j < s.size(); j++) {
                mpp[s[j] - 'a']++;

                if (mpp.size() > 1) {
                    int mini = INT_MAX;
                    int maxi = INT_MIN;

                    for (auto& it : mpp) {
                        mini = min(mini, it.second);
                        maxi = max(maxi, it.second);
                    }

                    count += (maxi - mini);
                }
            }
        }
        return count;
    }
};