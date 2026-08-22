class Solution:
    memo = []

    def helper(self, nums, i, n) -> int:
        if(i >= n):
            return 0

        if(self.memo[i] != -1):
            return self.memo[i]
        
        self.memo[i] = max(self.helper(nums, i+1, n), self.helper(nums, i+2, n) + nums[i])
        return self.memo[i]

    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        self.memo = [-1 for _ in range(len(nums))]
        a = self.helper(nums, 0, len(nums)-1)
        self.memo = []
        self.memo = [-1 for _ in range(len(nums))]
        b = self.helper(nums,1, len(nums))
        return max(a,b)
        