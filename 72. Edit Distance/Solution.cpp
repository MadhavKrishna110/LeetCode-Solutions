class Solution {
public:
    int helper(string word1,string word2,int i,int j,vector<vector<int>> &dp){
        if(i<0 ){
            return j+1;
        }
        if(j<0){
            return i+1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int pick=0,notPick=0;
        if(word1[i]==word2[j]){
            dp[i][j]= helper(word1,word2,i-1,j-1,dp);
        } else {
            int insert = 1+helper(word1,word2,i,j-1,dp);
            int replace = 1+helper(word1,word2,i-1,j-1,dp);
            int del = 1+helper(word1,word2,i-1,j,dp);
            dp[i][j]= min(insert,min(replace,del));
        }

        return dp[i][j];
        

    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));

        return helper(word1,word2,n1-1,n2-1,dp);
    }
};