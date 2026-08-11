class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        // sort(words.begin(),words.end());
        unordered_map<string, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[words[i]]++;
        }
        struct Cmp {
            bool operator()(const pair<int, string>& a,
                            const pair<int, string>& b) {
                if (a.first == b.first)
                    return a.second > b.second;

                return a.first < b.first;
            }
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, Cmp> pq;
        for (auto p : mpp) {
            pq.push({p.second, p.first});
        }
        int req = k;
        vector<string> ans;

        while (req != 0) {
            pair<int, string> top = pq.top();
            pq.pop();
            ans.push_back(top.second);
            req--;
        }

        return ans;
    }
};