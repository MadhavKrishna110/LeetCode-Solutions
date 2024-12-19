class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n=len(nums)
        if nums[n-1]>nums[n-2]:
            return nums[n-1]
        start, end = 0, n-1
        while start<end:
            mid = (start+end)//2
            if mid%2==0 and nums[mid]==nums[mid+1]:
                start=mid+1
            elif mid%2==0 and nums[mid]!=nums[mid+1]:
                end=mid
            elif mid%2!=0 and nums[mid]!=nums[mid+1]:
                start=mid+1
            elif mid%2!=0 and nums[mid]==nums[mid+1]:
                end=mid-1
            
        return nums[start]

        