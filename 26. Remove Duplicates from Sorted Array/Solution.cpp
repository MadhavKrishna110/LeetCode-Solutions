class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0,i=0;
        while(j<nums.size()){
            while(j<nums.size() && nums[j]==nums[i]){
                j++;
            }
            if(j<nums.size()){
                i++;
                nums[i]=nums[j];
            }
            
            j++;
        }
        return i<nums.size()?i+1:i;
    }
};