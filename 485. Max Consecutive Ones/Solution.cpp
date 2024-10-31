class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,maxm=0;
        while(j<nums.size()){
            if(nums[j]==0){
                maxm = max(maxm,j-i);
                i=j+1;
            } else {
                maxm = max(maxm,j-i+1);
            }
            j++;
        }
        return maxm;
    }
};