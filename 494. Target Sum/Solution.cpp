class Solution {
public:
    int fun(int idx,int target,vector<int> nums,unordered_map<int,unordered_map<int,int>> &mp){
        if(idx==nums.size() && target==0){
            return 1;
        }
        if(idx==nums.size()){
            return 0;
        }
        if(mp.find(idx)!=mp.end() && mp[idx].find(target)!=mp[idx].end()){
            return mp[idx][target];
        }

        int total =0;
        int add = fun(idx+1,target-nums[idx],nums,mp);
        int sub = fun(idx+1,target+nums[idx],nums,mp);
        total = add+sub;

        return mp[idx][target]=total;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,unordered_map<int,int>> mp;
        return fun(0,target,nums,mp);
    }
};