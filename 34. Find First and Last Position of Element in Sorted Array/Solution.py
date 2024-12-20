class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        start, end = 0, len(nums)-1
        while start<end and (nums[start]!=target or nums[end]!=target):
            mid = start+ (end-start)//2
            if nums[mid]>target:
                end = mid-1
            elif nums[mid]<target:
                start=mid+1
            else:
                if nums[start]!=target:
                    start+=1
                if nums[end]!=target:
                    end-=1
        
        print(start,end)
        if start>end or (nums[start]!=target or nums[end]!=target):
            return  [-1,-1]
        else:
            return [start,end]
        