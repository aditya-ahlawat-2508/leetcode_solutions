class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        /*
        nums-->n ints
        max value of k for which there exist two adjcent subarrays of length k
        each both subarrays strictly increasing specifically check there are two
        subarrays of length k starting at indices
        */
        int up = 1;
        int prevUp = 1;
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i]>nums[i-1]){
                up++;
            }else{
                prevUp=up;
                up=1;

            }
            int half=up/2;
            int m=min(up,prevUp);
            int cand=max(m,half);
            if(cand>res){
             res=cand;
            }

        }
        return res;
    }

}
;