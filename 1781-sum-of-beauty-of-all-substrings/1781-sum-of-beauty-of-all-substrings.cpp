class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                
                int mini = INT_MAX, maxi = INT_MIN;
                for (int f = 0; f < 26; f++) {
                    if (freq[f] == 0) continue;
                    mini = min(mini, freq[f]);
                    maxi = max(maxi, freq[f]);
                }
                
                count += (maxi - mini);
            }
        }
        
        return count;
    }
};