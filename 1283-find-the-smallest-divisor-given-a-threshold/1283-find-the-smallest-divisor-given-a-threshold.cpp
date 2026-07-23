class Solution {
public:
bool func(vector<int>& nums, int threshold, int mid){
  int count=0;
  for(int i=0;i<nums.size();i++){
    count+=ceil((double)nums[i]/mid);
  }
  return count<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        if (nums.size() > threshold)
            return -1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (func(nums, threshold, mid)) {
                ans = mid;
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};