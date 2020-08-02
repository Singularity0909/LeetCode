
// @Title: 复杂链表的复制 (复杂链表的复制  LCOF)
// @Author: Singularity0909
// @Date: 2020-08-01 22:12:43
// @Runtime: 16 ms
// @Memory: 11.4 MB

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, int> pos;
        vector<int> rand;
        Node* ptr = head;
        for (int i = 1; ptr; i++) {
            pos[ptr] = i;
            ptr = ptr->next;
        }
        Node* newHead = new Node(NULL);
        ptr = new Node(head->val);
        newHead->next = ptr;
        vector<Node*> nodes;
        while (true) {
            nodes.push_back(ptr);
            rand.push_back(pos[head->random]);
            if (!head->next) break;
            ptr = ptr->next = new Node(head->next->val);
            ptr->next = ptr->random = nullptr;
            head = head->next;
        }
        for (int i = 0; i < (int)nodes.size(); i++) {
            if (rand[i]) {
                nodes[i]->random = nodes[rand[i] - 1];
            }
        }
        return newHead->next;
    }
};
