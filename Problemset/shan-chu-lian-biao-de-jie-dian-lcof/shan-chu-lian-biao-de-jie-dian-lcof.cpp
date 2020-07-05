
// @Title: 删除链表的节点 (删除链表的节点 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-06 01:18:42
// @Runtime: 16 ms
// @Memory: 8.4 MB

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) return head->next;
        ListNode* p = head;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return head;
    }
};
