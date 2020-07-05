
// @Title: 从尾到头打印链表 (从尾到头打印链表 LCOF)
// @Author: Singularity0909
// @Date: 2020-07-06 01:22:21
// @Runtime: 8 ms
// @Memory: 8.9 MB

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
