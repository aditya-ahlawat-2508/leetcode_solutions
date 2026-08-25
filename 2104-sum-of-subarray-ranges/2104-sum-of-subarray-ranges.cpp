class Solution {
    
    // Previous Smaller
    vector<int> ps(vector<int>& arr, int n) {
        vector<int> pse(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(!st.empty())
                pse[i] = st.top();

            st.push(i);
        }

        return pse;
    }

    // Next Smaller
    vector<int> ns(vector<int>& arr, int n) {
        vector<int> nse(n, n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(!st.empty())
                nse[i] = st.top();

            st.push(i);
        }

        return nse;
    }

    // Previous Greater
    vector<int> pg(vector<int>& arr, int n) {
        vector<int> pge(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            if(!st.empty())
                pge[i] = st.top();

            st.push(i);
        }

        return pge;
    }

    // Next Greater
    vector<int> ng(vector<int>& arr, int n) {
        vector<int> nge(n, n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if(!st.empty())
                nge[i] = st.top();

            st.push(i);
        }

        return nge;
    }

public:

    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> pse = ps(nums, n);
        vector<int> nse = ns(nums, n);

        vector<int> pge = pg(nums, n);
        vector<int> nge = ng(nums, n);

        long long minimum = 0;
        long long maximum = 0;

        for(int i = 0; i < n; i++) {

            // Contribution as minimum
            long long left = i - pse[i];
            long long right = nse[i] - i;

            minimum += 1LL * nums[i] * left * right;


            // Contribution as maximum
            left = i - pge[i];
            right = nge[i] - i;

            maximum += 1LL * nums[i] * left * right;
        }

        return maximum - minimum;
    }
};