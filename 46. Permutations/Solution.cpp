class Solution {
public:
    void fun(vector<int>& nums,vector<int> &freq,vector<int> &v,vector<vector<int>> &ans){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                v.push_back(nums[i]);
                freq[i]=1;
                fun(nums,freq,v,ans);
                freq[i]=0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> freq(nums.size(),0);
        vector<int> v;
        vector<vector<int>> ans;

        fun(nums,freq,v,ans);
        return ans;
    }
};