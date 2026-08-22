class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        memo = []

        segment = []

        def permutation():
            if len(segment) == len(nums):
                memo.append(segment.copy())
                return
            for i in nums:
                if i not in segment:
                    segment.append(i)
                    permutation()
                    segment.pop()
        
        permutation()
        return memo