class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long> dp(amount + 1);
        dp[0] = 1;
       	//0 amount ke liye 1 way

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] = (dp[j]+ dp[j - coins[i]])%INT_MAX;
               	//dp[i][j]=dp[i+1][j]+dp[i][j-amt]
            }
        }

        return dp[amount];
    }
};