class Solution {
public:
    int fun(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int minCost = INT_MAX;
        for(int k=i+1;k<j;k++){
            int cost = fun(i,k,cuts,dp) + fun(k,j,cuts,dp) + cuts[j]-cuts[i];
            minCost = min(minCost,cost);
        }
        return dp[i][j]=minCost==INT_MAX?0:minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int c= cuts.size();
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return fun(0,c-1,cuts,dp);


    }
};