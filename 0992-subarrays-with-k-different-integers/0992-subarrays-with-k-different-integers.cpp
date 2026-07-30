class Solution {
public:
    int atMax(vector<int>& nums, int k) {
      int i=0;
      int j=0;
      int count=0;
      unordered_map<int,int>mpp;
      while(j<nums.size()){
        mpp[nums[j]]++;
        while(mpp.size()>k){
          mpp[nums[i]]--;
          if(mpp[nums[i]]==0){
            mpp.erase(nums[i]);
          }
          i++;
        }
        count+=(j-i+1);
        j++;
      }
      return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMax(nums, k) - atMax(nums, k - 1);
    }
};