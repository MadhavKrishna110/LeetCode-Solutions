class Solution {
public:
    int fun(int n,vector<int> &dp){
        if(dp[n]!=-1) return dp[n];
        dp[n] = fun(n-1,dp)+fun(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        int a=1,b=1;
        if(n<=1) return 1;
        for(int i=2;i<=n;i++){
         int sum = a+b;
         a=b;
         b=sum;
        }
        return b;
        
    }
};