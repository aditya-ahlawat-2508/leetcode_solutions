class Solution {
public:
    string expand(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--; // Expand outward [15, 18]
            right++;
        }
        // Return the valid palindrome found
        return s.substr(left + 1, right - left - 1); // right==4,left==0. for ex 1
    }

    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;
        string maxStr = s.substr(0, 1);

        for (int i = 0; i < s.length() - 1; i++) {
            // Try odd length expansion [15]
            string odd = expand(s, i, i);
            if (odd.length() > maxStr.length())
                maxStr = odd;

            // Try even length expansion [15]
            string even = expand(s, i, i + 1);
            if (even.length() > maxStr.length())
                maxStr = even;
        }
        return maxStr;
    }
};