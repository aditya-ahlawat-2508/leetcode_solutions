class Solution {
public:
    int trap(vector<int>& height) {
        int ans =0;
        int start=0;
        int end=height.size()-1;
        int lmax=0;
        int rmax=0;
        while(start<end){
            lmax=max(lmax,height[start]);
            rmax=max(rmax,height[end]);
            if(lmax<rmax){
                ans+= (lmax-height[start]);
                start++;
            }else{
                ans+= (rmax-height[end]);
                end--;
            }

        }
        return ans;
    }
};