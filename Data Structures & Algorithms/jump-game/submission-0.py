class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        goal = n-1
        i = n-2

        while i >= 0:
            if goal - i <= nums[i]:
                goal = i
            i -= 1
        
        return goal == 0