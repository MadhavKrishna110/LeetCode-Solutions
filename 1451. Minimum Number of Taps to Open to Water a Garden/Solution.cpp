class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        const int INF=1e9;
        vector<int> dp(n+1,INF);

        dp[0]=0;

        for(int i=0;i<=n;i++){
            int startTap = max(0,i-ranges[i]);

            int endTap = min(n,i+ranges[i]);

            for(int j=startTap;j<=endTap;j++){
                dp[endTap] = min(dp[endTap],dp[j]+1);
            }
        }

        if(dp[n]==INF){
            return -1;
        }
        return dp[n];
    }
};