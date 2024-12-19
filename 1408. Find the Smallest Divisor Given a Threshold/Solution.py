class Solution:
    def divisorSum(self, nums, k):
        sum=0
        for item in nums:
            if item%k==0:
                sum+=item//k
            else:
                sum+=(item//k)+1

        return sum
    
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        
        maxNumber = 0
        for item in nums:
            if item>maxNumber:
                maxNumber = item

        start, end = 1, maxNumber
        while start<end:
            mid = (start+end)//2
            val = self.divisorSum(nums,mid)
            if val>threshold:
                start=mid+1
            else:
                end=mid
        
        return start
