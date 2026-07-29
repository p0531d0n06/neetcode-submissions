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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = nullptr;
        for(auto i : lists){
            if(i == nullptr) continue;
            result = mergeList(result, i);
        }
        return result;
    }

    ListNode* mergeList(ListNode* a, ListNode* b){
        ListNode* result;


        if(a == nullptr || a -> val > b -> val){
            result = b;
            b = b -> next;
        } else {
            result = a;
            a = a -> next;
        }

        ListNode* resultHead = result;

        while(!(a == nullptr && b == nullptr)){
            if(a == nullptr || (b != nullptr && a->val > b->val)){
                result -> next = b;
                b = b -> next;
                result = result -> next;
            } else {
                result -> next = a;
                a = a -> next;
                result = result -> next;
            }
        }

        return resultHead;
    }
};
