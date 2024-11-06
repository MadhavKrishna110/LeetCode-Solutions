class Solution {
public:
int minCoins(int ind,int amount,vector<int> coins,vector<vector<int>> &dp){
    if(amount==0){
        return 0;
    }
    if(ind==0){
        if(amount%coins[ind]==0){
            return amount/coins[ind];
        }
        return 1e9;
    }
    if(dp[ind][amount]!=1e9){
        return dp[ind][amount];
    }
    if(coins[ind]<=amount){
        dp[ind][amount]= min(1+minCoins(ind,amount-coins[ind],coins,dp),minCoins(ind-1,amount,coins,dp));
    } else {
        dp[ind][amount] = minCoins(ind-1,amount,coins,dp);
    }
    return dp[ind][amount];
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(n+1,vector<int>(amount+1));
        for(int i=0;i<=amount;i++){
            dp[0][i]=1e9;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                   // cout<<i<<"-"<<j<<endl;
                    dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        return dp[n][amount]==1e9?-1:dp[n][amount];
    }
};