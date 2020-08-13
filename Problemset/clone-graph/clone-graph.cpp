
// @Title: 克隆图 (Clone Graph)
// @Author: Singularity0909
// @Date: 2020-08-13 17:43:10
// @Runtime: 8 ms
// @Memory: 8.9 MB

class Solution {
public:
    Node* dfs(Node* now, vector<Node*>& vec) {
        vec[now->val] = new Node(now->val);
        for (Node* nxt : now->neighbors) {
            vec[now->val]->neighbors.push_back(vec[nxt->val] ? vec[nxt->val] : dfs(nxt, vec));
        }
        return vec[now->val];
    }
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        vector<Node*> vec(101, nullptr);
        return dfs(node, vec);
    }
};
