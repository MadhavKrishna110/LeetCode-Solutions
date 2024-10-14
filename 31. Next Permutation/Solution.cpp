class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        // find the pivot element from suffix where nums[i]<nums[i+1]
        // from suffix, find the first number greater than pivot element 
        // swap both the numbers
        // reverse the suufix next to pivot element

        int i = n-1;
        while(i>0 && nums[i]<=nums[i-1]){
            i--;
        }
        if(i==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int pivot = i-1;
        int j=n-1;
        while(j>=pivot && nums[j]<=nums[pivot]){
            j--;
        }

        swap(nums[pivot],nums[j]);
        reverse(nums.begin()+pivot+1,nums.end());
    }
};