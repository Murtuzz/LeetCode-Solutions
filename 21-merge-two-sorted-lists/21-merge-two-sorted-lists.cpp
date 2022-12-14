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
        
        if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        }
        
        ListNode *head, *headClone;
        
        if (list1->val > list2->val) {
            head = new ListNode(list2->val);
            list2 = list2->next;
        } else {
            head = new ListNode(list1->val);
            list1 = list1->next;
        }
        
        headClone = head;
        
        while (list1 && list2) {
            if (list1->val > list2->val) {
                headClone->next = new ListNode(list2->val);
                list2 = list2->next;
            } else {
                headClone->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            headClone = headClone->next;
        }
        
        if (!list1) {
            list1 = list2;
        }
        
        headClone->next = list1;
        return head;
    }
};