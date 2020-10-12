
// @Title: 两两交换链表中的节点 (Swap Nodes in Pairs)
// @Author: Singularity0909
// @Date: 2020-10-13 00:37:38
// @Runtime: 0 ms
// @Memory: 7.5 MB

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (not head or not head->next) {
            return head;
        }
        ListNode* p = head;
        ListNode* newHead = head->next;
        ListNode* a;
        ListNode* b;
        ListNode* lst = nullptr;
        while (p) {
            if (p->next) {
                if (lst) {
                    lst->next = p->next;
                }
                a = p;
                b = a->next;
                a->next = p = b->next;
                lst = b->next = a;
            } else {
                break;
            }
        }
        return newHead;
    }
};
