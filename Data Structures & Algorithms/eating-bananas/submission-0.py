class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        maxK = max(piles)
        minK = 1
        
        result = maxK

        def getHours(k) -> int:
            res = 0
            for i in piles:
                res += math.ceil(i / k)
            return res
        
        while(minK <= maxK):
            m = (minK+maxK) // 2
            if getHours(m) <= h:
                result = min(result, m)
                maxK = m-1
            else:
                minK = m+1
        
        return result

