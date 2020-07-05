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