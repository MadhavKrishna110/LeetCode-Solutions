class Solution(object):
    def findKthPositive(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        i, cnt = 1, 0
        while cnt<k:
            if i not in arr:
                cnt+=1
            if cnt==k:
                return i
            i+=1
        return i
           
        