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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        while(list1 != NULL || list2 != NULL){

            if(list1 == NULL){
                current->next = new ListNode(list2->val);
                current = current->next;
                list2 = list2->next;
                continue;
            }
            else if(list2 == NULL){
                current->next = new ListNode(list1->val);
                current = current->next;
                list1 = list1->next;
                continue;
            }

            if(list1->val <= list2->val){
                current->next = new ListNode(list1->val);
                current = current->next;
                list1 = list1->next;
            }
            else{
                current->next = new ListNode(list2->val);
                current = current->next;
                list2 = list2->next;
            }
        }

        return head->next;
    }
};