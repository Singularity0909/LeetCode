
// @Title: 删除链表的倒数第N个节点 (Remove Nth Node From End of List)
// @Author: Singularity0909
// @Date: 2020-10-18 19:32:36
// @Runtime: 4 ms
// @Memory: 10.8 MB

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* lst = new ListNode(0, head);
        ListNode* pa = lst;
        ListNode* pb = head;
        while (n--) {
            pb = pb->next;
        }
        while (pb) {
            pb = pb->next;
            pa = pa->next;
        }
        pa->next = pa->next->next;
        return lst->next;
    }
};
