class Solution {
public:
    void fun(int ind,vector<int> nums,int target,vector<int> &v,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(v);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            if(nums[i]<=target){
                v.push_back(nums[i]);
                fun(i,nums,target-nums[i],v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        fun(0,candidates,target,v,ans);
        return ans;
    }
};