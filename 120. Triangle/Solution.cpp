class Solution {
public:
    int fun(int i,int j,vector<vector<int>> &dp, vector<vector<int>> &triangle){
        if(i>=triangle.size() || j>i) return 0;
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        return dp[i][j]=triangle[i][j] + min(fun(i+1,j,dp,triangle),fun(i+1,j+1,dp,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(0,0,dp,triangle);
    }
};