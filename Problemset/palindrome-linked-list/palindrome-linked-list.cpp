
// @Title: 回文链表 (Palindrome Linked List)
// @Author: Singularity0909
// @Date: 2020-10-23 13:46:50
// @Runtime: 32 ms
// @Memory: 14.7 MB

class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        vector<int> val;
        while (head) {
            val.push_back(head->val);
            head = head->next;
        }
        for (int i = 0; i < (int)val.size() / 2; ++i) {
            if (val[i] != val[val.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
