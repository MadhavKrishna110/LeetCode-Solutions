class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix=1,suffix=1;
        int maxm=INT_MIN;
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;

            prefix*=nums[i];
            suffix*=nums[n-i-1];
            maxm = max(maxm,max(prefix,suffix));
        }
        return maxm;
    }
};