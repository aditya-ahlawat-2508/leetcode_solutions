class Solution {
public:
bool check(vector<int> &arr, int k,int mid){
      int cnt=1;
      int prev_val=arr[0];
      for(int i=1;i<arr.size();i++){
          prev_val+=arr[i];
          if(prev_val > mid){
              cnt++;
              prev_val=arr[i];
          }
      }
      return cnt <= k;
  }
    int findPages(vector<int> &arr, int k) {
        if(arr.size()<k) return -1;
        if(arr.size()==k) return *max_element(arr.begin(),arr.end());
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(arr,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        // this question is exactly similar to the book allocation problem 
      return findPages(nums,k);
    }
};

/*
1,2,3,4,5.  k=2;
1.         |.  2,3,4,5.  -->14
1,2.       |.  3,4,5.    -->12
1,2,3.     |.  4,5.                    -->9.  ********
1,2,3,4.   |.  5.        -->10


*/