class Solution {
public:
    int binarySearch(int start,int end,vector<int> nums,int target){
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            } else if(nums[mid]>target){
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       int start=0,end=nums.size()-1;
       int partition=-1;
       while(start<end){
        int mid = start+(end-start)/2;
         if(nums[mid]>nums[mid+1]){
            partition=mid;
            break;
         } else if(nums[mid]>nums[end]){
            start=mid+1;
         } else {
            end = mid;
         }
       }
       cout<<partition<<endl;
       if(partition==-1){
        return binarySearch(0,nums.size()-1,nums,target);
       } else {
        int ans = binarySearch(0,partition,nums,target);
        if(ans!=-1){
            return ans;
        }
        return binarySearch(partition+1,nums.size()-1,nums,target);
       }
       return -1;

    }
};