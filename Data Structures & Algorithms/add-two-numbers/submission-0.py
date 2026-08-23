# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode], c = 0) -> Optional[ListNode]:
        if l1 is None and l2 is None and c==0:
            return None
        
        value = c
        if l1 is not None:
            value += l1.val
            l1 = l1.next
        if l2 is not None: 
            value += l2.val
            l2 = l2.next


        res = ListNode(val = value % 10)

        res.next = self.addTwoNumbers(l1, l2, value // 10)

        return res