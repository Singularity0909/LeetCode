
// @Title: 链表中倒数第k个节点 (链表中倒数第k个节点 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-06 01:17:46
// @Runtime: 4 ms
// @Memory: 10.7 MB

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* ptr = head;
        for (int i = 0; i < k; i++) ptr = ptr->next;
        while (ptr) {
            ptr = ptr->next;
            head = head->next;
        }
        return head;
    }
};
