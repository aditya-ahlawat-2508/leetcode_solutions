class Solution {
public:
bool check(int l, int r,int k,vector<int>&left,vector<int>&right){

    for(int i=1;i<left.size();i++){
        if(left[i-1] >=k && right[i] >= k){
            return true;
        }
    }
    return false;
}
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                left[i]=left[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                right[i]=right[i+1]+1;
            }
        }
        // now we have the left and right subarrays which consist of the maximum subaarays ending at a particular index
        int l=1;
        int h=n/2;
        int ans=1;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(l,h,mid,left,right)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};