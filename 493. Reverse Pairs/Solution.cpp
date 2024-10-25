class Solution {
public:
    int fun(vector<int> &nums,int low,int high){
        int cnt=0;
        if(low>=high) return cnt;
        int mid = low+(high-low)/2;

        cnt = fun(nums,low,mid)+fun(nums,mid+1,high);

        for(int i=low,j=mid+1;i<=mid;i++){
            while(j<=high && nums[i]/2.0>nums[j]) j++;
            cnt+=(j-(mid+1));
        }
       
        sort(nums.begin()+low,nums.begin()+high+1);
      

        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return fun(nums,0,nums.size()-1);
    }
};