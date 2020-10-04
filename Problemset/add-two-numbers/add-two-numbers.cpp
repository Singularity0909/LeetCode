
// @Title: 两数相加 (Add Two Numbers)
// @Author: Singularity0909
// @Date: 2020-10-04 22:26:56
// @Runtime: 64 ms
// @Memory: 69.6 MB

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        bool carry = false;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (not head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
