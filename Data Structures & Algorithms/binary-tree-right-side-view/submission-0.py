# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        memo = []

        level = [root]

        while level:
            memo.append(level[-1].val)
            n = len(level)
            for _ in range(n):
                if level[0].left is not None:
                    level.append(level[0].left)
                if level[0].right is not None:
                    level.append(level[0].right)
                level.pop(0)

        
        return memo
            
