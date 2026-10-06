class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s.size() == 0)
            return 0;
        int n = s.size();
        int count = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
            } else {
                if (count != 0) {
                    count--;
                }else{
                    ans++;
                }
            }
        }
        return ans + count;
    }
};