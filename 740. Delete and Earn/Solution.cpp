class Solution {
public:
    int maxPoints(int num,unordered_map<int,int> &mp,vector<int> &dp){
        if(num<=0) return 0;

        if(dp[num]!=-1){
            return dp[num];
        }
        cout<<num<<"-"<<mp[num]<<endl;
        dp[num]= max(maxPoints(num-1,mp,dp),mp[num]+maxPoints(num-2,mp,dp));
        return dp[num];

    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxNumber=nums[0];
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=nums[i];
            maxNumber = max(maxNumber,nums[i]);
        }
        vector<int> dp(maxNumber+1,-1);
        return maxPoints(maxNumber,mp,dp);
    }
};