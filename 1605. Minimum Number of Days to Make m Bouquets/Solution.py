class Solution(object):

    def possible(self, bloomDay, m, k, day):
        n = len(bloomDay)
        i=0
        bouqet=0
        while i<n :
            cnt=0
            while i<n and day>=bloomDay[i] and cnt<k:
                cnt+=1
                if cnt<k:
                    i+=1
            if cnt==k:
                bouqet+=1
            i+=1
        return bouqet>=m

    def minDays(self, bloomDay, m, k):
        """
        :type bloomDay: List[int]
        :type m: int
        :type k: int
        :rtype: int
        """
        if m*k>len(bloomDay):
            return -1

        maxDay = bloomDay[0]
        minDay = bloomDay[0]
        for i in range(1,len(bloomDay)):
            maxDay = max(maxDay,bloomDay[i])
            minDay = min(minDay,bloomDay[i])

        low, high = minDay, maxDay

        while low<high:
            mid = (low+high)//2
            value = self.possible(bloomDay,m,k,mid)
            if value:
                high=mid
            else :
                low=mid+1
        
        return high

