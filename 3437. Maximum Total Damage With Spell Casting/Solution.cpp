class Solution {
    #define ll long long
public:
    long long getMaxDamage(int idx,vector<int> &uniquePowers,vector<long long> &dp,map<int,int> &frequencyMap){
        if(idx== uniquePowers.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];

        long long skip = getMaxDamage(idx+1,uniquePowers,dp,frequencyMap);

        long long take =0;
        int nextStep = idx+1;
        while(nextStep<uniquePowers.size() && uniquePowers[nextStep]-uniquePowers[idx]<=2){
            nextStep++;
        }
        take = ((1ll)*frequencyMap[uniquePowers[idx]]*uniquePowers[idx]) + getMaxDamage(nextStep,uniquePowers,dp,frequencyMap);
        return dp[idx] = skip>take? skip: take;
    }
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        map<int,int> damageFrequency;

        for(int i=0;i<power.size();i++){
            damageFrequency[power[i]]++;
        }
        vector<int> arr;
        for(auto i:damageFrequency){
            arr.push_back(i.first);
        }


        vector<long long> dp(arr.size(),-1);
        
        return getMaxDamage(0,arr,dp,damageFrequency);
    }
};