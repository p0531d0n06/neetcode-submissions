class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:

        memo = {}

        def dtree(i, acc) -> int:
            if (i,acc) in memo.keys():
                return memo[(i, acc)]
            if i == len(nums):
                if acc == target:
                    return 1
                return 0
            res = dtree(i+1, acc - nums[i]) + dtree(i+1, acc + nums[i])
            memo[(i, acc)] = res
            return res
        
        
        return dtree(0,0)
