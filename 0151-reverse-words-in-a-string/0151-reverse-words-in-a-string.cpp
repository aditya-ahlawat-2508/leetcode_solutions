class Solution {
public:
    string reverseWords(string s) {

        // Reverse entire string
        reverse(s.begin(), s.end());

        // Remove leading spaces
        while (!s.empty() && s.front() == ' ')
            s.erase(s.begin());

        // Remove trailing spaces
        while (!s.empty() && s.back() == ' ')
            s.pop_back();

        int start = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == ' ') {

                // Reverse current word
                reverse(s.begin() + start, s.begin() + i);

                // Remove extra spaces
                while (i + 1 < s.size() && s[i + 1] == ' ')
                    s.erase(i + 1, 1);

                start = i + 1;
            }
        }

        // Reverse last word
        reverse(s.begin() + start, s.end());

        return s;
    }
};