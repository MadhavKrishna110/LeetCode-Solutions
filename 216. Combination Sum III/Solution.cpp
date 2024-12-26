class Solution {
public:
    void fun(int num,int target,int k, vector<int> &res,vector<vector<int>> &ans){
        if(target==0){
            if(res.size()==k){
                ans.push_back(res);
            }
            return;
        }
        if(num>9) return;

        for(int i=num;i<=9;i++){
            if(i>target) break;
            res.push_back(i);
            fun(i+1,target-i,k,res,ans);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;
        fun(1,n,k,res,ans);
        return ans;
    }
};