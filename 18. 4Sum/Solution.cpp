class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int n= nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left =j+1, right = n-1;
                long long updatedTarget = (long long) target-nums[i]-nums[j];
                while(left<right){
                    long long sum = nums[left]+nums[right];
                    if(sum<updatedTarget){
                        left++;
                    } else if(sum>updatedTarget){
                        right--;
                    } else {
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[left]);
                        ans.push_back(nums[right]);
                        result.push_back(ans);

                        left++;
                        right--;
                        while(left<right && nums[left-1]==nums[left]) left++;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return result;
    }
};