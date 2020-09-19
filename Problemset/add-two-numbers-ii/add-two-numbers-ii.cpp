
// @Title: 两数相加 II (Add Two Numbers II)
// @Author: Singularity0909
// @Date: 2020-09-17 22:59:32
// @Runtime: 40 ms
// @Memory: 69.5 MB

class Solution {
public:
    string addStrings(string num1, string num2) {
        int len = (int)max(num1.length(), num2.length());
        if (num1.length() < len) num1 = string(len - num1.length(), '0') + num1;
        else num2 = string(len - num2.length(), '0') + num2;
        string res;
        bool flag = false;
        for (int i = len - 1; i >= 0; i--) {
            int val = num1[i] + num2[i] - '0' * 2 + flag;
            res.push_back((val % 10) + '0');
            flag = val / 10;
        }
        if (flag) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string num1, num2;
        while (l1) {
            num1.push_back(l1->val + '0');
            l1 = l1->next;
        }
        while (l2) {
            num2.push_back(l2->val + '0');
            l2 = l2->next;
        }
        string ans = addStrings(num1, num2);
        ListNode* newList = nullptr;
        ListNode* tmp;
        while (!ans.empty()) {
            tmp = new ListNode(ans.back() - '0');
            tmp->next = newList;
            ans.pop_back();
            newList = tmp;
        }
        return newList;
    }
};
