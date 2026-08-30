class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int sum = 0;
        int  count=0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum==k){
              count++;
            }
            int need=sum-k;
            if(mpp.find(need)!=mpp.end()){
              count+=mpp[need];
            }
            mpp[sum]++;
        }
        return count;
    }
};