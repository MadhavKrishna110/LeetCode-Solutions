class Solution(object):
    def fun(self,piles,h,k):
        pileSize = len(piles)
        i=0
        cnt=0
        while i<pileSize:
            cnt+=(piles[i]+k-1)//k
            i+=1
        return cnt<=h

    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        totalBananas = 0
        for i in range(len(piles)):
            totalBananas+=piles[i]
        low=1
        high=totalBananas
        while low<high:
            mid = (low+high)/2
            value = self.fun(piles,h,mid)
            if value:
                high=mid
            else:
                low=mid+1

        return high

        