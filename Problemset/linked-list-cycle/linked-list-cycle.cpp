
// @Title: 环形链表 (Linked List Cycle)
// @Author: Singularity0909
// @Date: 2020-10-09 12:00:41
// @Runtime: 4 ms
// @Memory: 7.6 MB

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
