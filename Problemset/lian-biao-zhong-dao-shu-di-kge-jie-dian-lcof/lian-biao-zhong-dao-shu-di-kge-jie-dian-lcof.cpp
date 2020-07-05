
// @Title: 链表中倒数第k个节点 (链表中倒数第k个节点 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-04 22:59:47
// @Runtime: 4 ms
// @Memory: 10.7 MB

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* ptr = head;
        for (int i = 0; i < k; i++) ptr = ptr->next;
        while (ptr) {
            ptr = ptr->next;
            head = head->next;
        }
        return head;
        // if (head == nullptr) return nullptr;
        // int n = 0;
        // ListNode* ptr = head;
        // while (ptr) {
        //     n++;
        //     ptr = ptr->next;
        // }
        // if (k > n) return nullptr;
        // for (int i = 0; i < n - k; i++)
        //     head = head->next;
        // return head;
    }
};
