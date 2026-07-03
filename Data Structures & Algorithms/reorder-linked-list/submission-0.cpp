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
    void reorderList(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            temp = temp -> next;
            length += 1;
        }

        ListNode* l1 = head;
        ListNode* l2 = head;

        for (int i = 0; i < (length - 1) / 2; i++) {
            l2 = l2 -> next;
        }
        ListNode* l2_temp = l2;
        l2 = l2 -> next;
        l2_temp -> next = nullptr;

        // reverse l2 and so on 
        ListNode* prev = nullptr;
        ListNode* curr = l2;

        while (curr != nullptr) {
            ListNode* nextTemp = curr -> next;
            curr -> next = prev;               
            prev = curr;                       
            curr = nextTemp;                   
        }

        l2 = prev;
        while (l2 != nullptr && l1 != nullptr){
            ListNode* l1Next = l1 -> next;
            ListNode* l2Next = l2 -> next;

            l1 -> next = l2;
            if (l1Next != nullptr) {
                l2 -> next = l1Next;
            }

            l1 = l1Next;
            l2 = l2Next;
        }
    }
};
