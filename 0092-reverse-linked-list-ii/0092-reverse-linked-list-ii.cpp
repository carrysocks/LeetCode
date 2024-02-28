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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* before = new ListNode(0);
        before->next = head;
        ListNode* current = before;
        for(int i=0;i<left-1;i++){
            current = current->next;
        }

        ListNode* pre = current;
        ListNode* cur = pre->next;
        ListNode* nxt;
        for(int i=0;i<right-left;i++){
            nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }

        return before->next;
    }
};
