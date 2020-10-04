
// @Title: 反转链表 (反转链表 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-06 01:17:15
// @Runtime: 12 ms
// @Memory: 8.5 MB

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
