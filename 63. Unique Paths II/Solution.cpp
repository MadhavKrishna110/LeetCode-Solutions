class Solution {
public:
    int fun(int i,int j,int m,int n,vector<vector<int>> &dp,vector<vector<int>> & arr){
        if(i>=m || j>=n || arr[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int rightWay = 0,downWay=0;
        if(j+1<n && !arr[i][j+1]){
            rightWay = fun(i,j+1,m,n,dp,arr);
        }
        if(i+1<m && !arr[i+1][j]){
            downWay = fun(i+1,j,m,n,dp,arr);
        }

        return dp[i][j]=rightWay+downWay;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(0,0,m,n,dp,obstacleGrid);
    }
};