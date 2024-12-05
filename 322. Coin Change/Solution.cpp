class Solution {
public:
    int fun(int ind,int amount,vector<int>& coins, vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int minm = 1e9;
        for(int i=ind;i<coins.size();i++){
            if(coins[i]<=amount){
                minm = min(minm,1+fun(i,amount-coins[i],coins,dp));
            }
        }
        return dp[ind][amount]=minm;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res= fun(0,amount,coins,dp);
        return res==1e9?-1:res-1;
    }
};