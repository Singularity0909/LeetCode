
// @Title: 合并两个有序链表 (Merge Two Sorted Lists)
// @Author: Singularity0909
// @Date: 2020-07-06 01:16:43
// @Runtime: 12 ms
// @Memory: 14.2 MB

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
