class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1,curr=0;
        while(curr<=j){
            if(nums[curr]==0){
                swap(nums[i],nums[curr++]);
                i++;
            } else if(nums[curr]==2){
                swap(nums[curr],nums[j]);
                j--;
            } else {
                curr++;
            }
            
        }


    }
};