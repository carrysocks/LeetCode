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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode(0);
        prev->next = head;

        ListNode* left = prev;
        ListNode* right = left->next;
        int idx = 1;

        while(right != nullptr){
            if(right->next == nullptr || left->next->val != right->next->val){
                if(idx > 1){
                    left->next = right->next;
                    right = right->next;
                    idx = 1; 
                }
                else{
                    left = left->next;
                    right = right->next;
                }
            } 
            else{
                idx++;
                right = right->next;
            }
        }

        return prev->next;
    }
};