
// @Title: 合并两个有序链表 (Merge Two Sorted Lists)
// @Author: Singularity0909
// @Date: 2020-07-05 11:55:39
// @Runtime: 8 ms
// @Memory: 14.5 MB

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head, *ptr;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        ptr = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ptr = ptr->next = l1;
                l1 = l1->next;
            }
            else {
                ptr = ptr->next = l2;
                l2 = l2->next;
            }
        }
        ptr->next = l1 ? l1 : l2;
        return head;
    }
};
