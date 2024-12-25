class Solution {
public:
    void fun(int idx,int target,vector<int> &res, vector<int> candidates,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(res);
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            if(candidates[i]<=target){
                res.push_back(candidates[i]);
                fun(i,target-candidates[i],res,candidates,ans);
                res.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        fun(0,target,res,candidates,ans);
        return ans;
    }
};