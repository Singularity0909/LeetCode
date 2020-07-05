
// @Title: 反转链表 (反转链表 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-05 14:04:03
// @Runtime: 12 ms
// @Memory: 8.7 MB

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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* last = nullptr;
        ListNode* now = new ListNode(head->val);
        now->next = last;
        head = head->next;
        while (head) {
            ListNode* tmp = new ListNode(head->val);
            tmp->next = now;
            now = tmp;
            head = head->next;
        }
        return now;
    }
};
