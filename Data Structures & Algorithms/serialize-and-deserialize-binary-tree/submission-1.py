# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        if root is None : return "N"
        return str(root.val) + '.' + self.serialize(root.left) +'.'+ self.serialize(root.right)


        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        elements = data.split('.')

        def build():
            if elements[0] == 'N':
                elements.pop(0)
                return None
            else:
                curr = TreeNode(int(elements[0]))
                elements.pop(0)
                curr.left = build()
                curr.right = build()
                return curr
        
        return build()
        
        
