class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=1,end=nums.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mid%2==0){
                if(nums[mid]>nums[mid-1]){
                    start=mid+1;
                } else {
                     end=mid-1;
                }
            } else {
                 if(nums[mid]==nums[mid-1]){
                    start=mid+1;
                } else {
                    end=mid-1;
                }
            }
        }
        cout<<start<<"-"<<end<<endl;
        return nums[start-1];
    }
};