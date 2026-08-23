class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        i = 0
        j = 0

        i = nums[i]
        j = nums[nums[j]]
        while(i != j):
            i = nums[i]
            j = nums[nums[j]]

        k = 0

        while(k != i):
            i = nums[i]
            k = nums[k]
        
        return k
        
