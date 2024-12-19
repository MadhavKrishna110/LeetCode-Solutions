class Solution:
    def loadPackages(self,weights,limit):
        arrSize = len(weights)
        sum, i=0, 0
        cnt=0
        while i<arrSize:
            while i<arrSize and sum+weights[i]<=limit:
                sum+=weights[i]
                i+=1
            cnt+=1
            sum=0
        return cnt


    def shipWithinDays(self, weights: List[int], days: int) -> int:
        sum, maxItem=0,weights[0]
        for item in weights:
            sum+=item
            if item>maxItem:
                maxItem = item
        
        start, end = maxItem, sum
        while start<end:
            mid = (start+end)//2
            val = self.loadPackages(weights,mid)
           
            if val<=days:
                end = mid
            else:
                start=mid+1
        
        return start
        
