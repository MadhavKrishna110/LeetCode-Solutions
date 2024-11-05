class Solution {
public:
int fun(int i,int remain,vector<int> cost, vector<int> time,vector<vector<int>> dp){
    if(remain<=0){
        return 0;
    }
    if(i==cost.size()){
        return 1e9;
    }
    int hire = cost[i]+fun(i+1,remain-1-time[i],cost,time,dp);
    int donthire = fun(i+1,remain,cost,time,dp);
    dp[i][remain] = min(hire,donthire);
    return dp[i][remain];
}
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        vector<int> prevDp(n+1,1e9);
       prevDp[0]=0;
        for(int i=n-1;i>=0;i--){
            dp=vector(n+1,0);
            for(int j=1;j<=n;j++){
                int hire = cost[i]+prevDp[max(0,j-1-time[i])];
                int donthire = prevDp[j];
                int minm = min(hire,donthire);
                dp[j]=minm;
            }
            prevDp=dp;
        }
        return dp[n];
        
    }
};