class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int subsetSum=sum/2;
        int n=nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(subsetSum+1));
       
        for(int i=0;i<=n;i++){
            
            for(int j=0;j<=subsetSum;j++){
                if(j==0||i==0){
                    dp[i][j]=false;
                } else if(nums[i-1]<j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                } else if(nums[i-1]>j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j]=true;
                }
            }
        }

        return dp[n][subsetSum];

    }
};