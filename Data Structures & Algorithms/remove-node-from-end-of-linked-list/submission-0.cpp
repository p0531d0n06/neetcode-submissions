/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l  = 0;
        auto hcopy = head;

        while(hcopy != nullptr){
            l++;
            hcopy = hcopy -> next;
        }

        hcopy = head;
        int lc = l - n;
        while(lc > 1){
            hcopy = hcopy -> next;
            lc--;
        }
        
        if(l == n){
            return head -> next;
        } else {
            hcopy -> next = (hcopy -> next) -> next;
            return head;
        }
            
    }
};
