class Solution {
public:
    int lcs(int ind1,int ind2,string text1,string text2,vector<vector<int>> &dp){
        if(ind1>=text1.size() || ind2>=text2.size()){
            return 0;
        }

        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int pick = 0,notPick=0;
        if(text1[ind1]==text2[ind2]){
            pick = 1+lcs(ind1+1,ind2+1,text1,text2,dp);
        } else{
            notPick = max(lcs(ind1+1,ind2,text1,text2,dp),lcs(ind1,ind2+1,text1,text2,dp));
        }

        return dp[ind1][ind2] = max(pick,notPick);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];

        return lcs(0,0,text1,text2,dp);
    }
};