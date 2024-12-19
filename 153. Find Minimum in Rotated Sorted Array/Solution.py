class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n==1:
            return nums[0]
        if nums[0]<nums[n-1]:
            return nums[0]
        start, end = 1, n-1
        while start<end:
            mid = start + (end-start)//2
            if nums[mid]>nums[mid-1]:
                if nums[mid]>nums[0]:
                    start=mid+1
                else:
                    end=mid-1
            else:
                return nums[mid]
        
        return nums[start]