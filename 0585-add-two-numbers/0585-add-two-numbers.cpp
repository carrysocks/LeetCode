/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int bal = 0;
        while(l1 && l2)
        {
            *l1->val = *l1->val + *l2->val + bal;
            bal = *l1->val/10;
            *l1->val %= 10;
        }
        if(*l1 == NULL)
            *l1 = *l2;
            
        *l1->val += bal;
        return *l1;
    }
};