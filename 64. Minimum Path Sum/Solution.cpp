class Solution {
public:
    int fun(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &arr){
        if(i<0 || j<0) return INT_MAX;
        if(i==0 && j==0){
            return arr[0][0];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]= arr[i][j]+max(0,min(fun(i-1,j,dp,arr),fun(i,j-1,dp,arr)));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,dp,grid);
    }
};