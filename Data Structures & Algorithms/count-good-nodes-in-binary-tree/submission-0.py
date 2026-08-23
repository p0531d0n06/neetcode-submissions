# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        

        def dfs(root, greatestVal) -> int:
            res = 0
            if root is None:
                return 0
            if(root.val >= greatestVal):
                res += 1
                greatestVal = root.val
            
            res += dfs(root.left, greatestVal)
            res += dfs(root.right, greatestVal)

            return res
        
        return dfs(root, root.val)
        