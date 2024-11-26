class Solution {
public:
    int fun(int ind,vector<int> &dp,vector<int> nums){
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        dp[ind]= max(nums[ind]+fun(ind+2,dp,nums),fun(ind+1,dp,nums));
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return fun(0,dp,nums);
    }
};