class Solution {
public:
    int fun(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& matrix){
        if(j<0 || i>=matrix.size() || j>=matrix[0].size()) return 1e9;
        if(i==matrix.size()-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int res1 = fun(i+1,j-1,dp,matrix);
        int res2 = fun(i+1,j,dp,matrix);
        int res3 = fun(i+1,j+1,dp,matrix);

       return  dp[i][j]= matrix[i][j]+min(res1,min(res2,res3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minm=INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<matrix[0].size();i++){
            minm = min(minm,fun(0,i,dp,matrix));
        }
        return minm;
    }
};