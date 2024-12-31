class Solution {
public:
    int fun(int idx,int k, vector<int> &arr,vector<int> &dp){
        if(idx>=arr.size()) return 0;
        int n = arr.size();
        if(dp[idx]!=-1) return dp[idx];
        int maxSum=0;
        for(int i=idx;i<n;i++){
            int maxNumber = arr[i];
            for(int j=0;j<k;j++){
                if(i+j>=n){
                    break;
                }
                maxNumber = max(maxNumber,arr[i+j]);
                int sum = maxNumber*(j+1) + fun(i+j+1,k,arr,dp);
                maxSum = max(maxSum,sum);
            }
        }
        return dp[idx]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return fun(0,k,arr,dp);
    }
};