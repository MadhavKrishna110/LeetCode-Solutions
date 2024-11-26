class Solution {
public:
    int fun(int ind,vector<int> &dp,vector<int> nums){
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        dp[ind] = max(fun(ind+2,dp,nums)+nums[ind],fun(ind+1,dp,nums));
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        else if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> dp(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        vector<int> v1(nums.begin()+1,nums.end());
        vector<int> v2(nums.begin(),nums.end()-1);
        return max(fun(0,dp,v1),fun(0,dp2,v2));
    }
};