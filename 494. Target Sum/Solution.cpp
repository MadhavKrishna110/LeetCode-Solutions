class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // s2-s1=target
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum<target || (sum-target)%2!=0) return 0;
        int findTarget = (sum-target)/2;

        vector<vector<int>> dp(n,vector<int>(findTarget+1,0));

        if(nums[0]==0){
            dp[0][0]=2;
        } else {
            dp[0][0]=1;
        }

        if(nums[0]!=0 && nums[0]<=findTarget) dp[0][nums[0]] = 1;

        for(int idx=1;idx<n;idx++){
            for(int j=0;j<=findTarget;j++){
                int take=0;
                if(nums[idx]<=j){
                    take = dp[idx-1][j-nums[idx]];
                }
                int notTake = dp[idx-1][j];
                dp[idx][j] = take+notTake;
            }
        }
        return dp[n-1][findTarget];

    }
};