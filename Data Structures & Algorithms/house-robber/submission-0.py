class Solution:
    memo = []

    def helper(self, nums, i) -> int:
        if(i >= len(nums)):
            return 0

        if(self.memo[i] != -1):
            return self.memo[i]
        
        self.memo[i] = max(self.helper(nums, i+1), self.helper(nums, i+2) + nums[i])
        return self.memo[i]

    def rob(self, nums: List[int]) -> int:
        self.memo = [-1 for _ in range(len(nums))]
        return self.helper(nums, 0)
