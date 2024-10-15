class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int freq = nums.size()/3;

        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto i:mp){
            if(i.second>freq){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};