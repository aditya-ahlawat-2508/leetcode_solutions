class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
          mpp[it]++;
        }
        for(auto &p:mpp){
          if(p.second==1){
            return p.first;
          }
        }
        return 0;
    }
};