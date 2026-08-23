class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sort and compare the first and the last
        sort(strs.begin(), strs.end());
        string st = strs.front();
        string ed = strs.back();
        string ans = "";
        for (int i = 0; i < min(st.size(), ed.size()); i++) {
            if (st[i] == ed[i]) {
                ans += st[i];
            } else {
                return ans;
            }
        }
        return ans;
    }
};