class Solution {
public:
    void fun(int ind,vector<int> nums,vector<int> &v,vector<vector<int>> &res){
        res.push_back(v);

        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            fun(i+1,nums,v,res);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        vector<vector<int>> ans;
        fun(0,nums,v,ans);
        return ans;
    }
};