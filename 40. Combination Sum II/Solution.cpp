class Solution {
public:
    void fun(int idx,int target,vector<int> &res,vector<int> nums,set<vector<int>> &ans){
        if(target==0){
            ans.insert(res);
            return;
        }
        if(idx==nums.size() ){
            return;
        }

        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            res.push_back(nums[i]);
            fun(i+1,target-nums[i],res,nums,ans);
            res.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>> ans;
        vector<int> res;
        fun(0,target,res,candidates,ans);
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;

    }
};