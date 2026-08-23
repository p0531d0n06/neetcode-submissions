"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None
        memo = {}

        copy = head

        while copy != None:
            nodeCopy = Node(copy.val)
            memo[copy] = nodeCopy
            copy = copy.next
        
        copy = head

        while copy != None:
            if copy.next is not None:
                memo[copy].next = memo[copy.next]
            if copy.random is not None:
                memo[copy].random = memo[copy.random] 
            copy = copy.next

        return memo[head]


