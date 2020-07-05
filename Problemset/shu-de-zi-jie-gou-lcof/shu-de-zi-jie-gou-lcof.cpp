
// @Title: 树的子结构 (树的子结构  LCOF)
// @Author: Singularity0909
// @Date: 2020-07-05 12:29:20
// @Runtime: 68 ms
// @Memory: 33.8 MB

class Solution {
public:
    bool equal(TreeNode* A, TreeNode* B) {
        if (!A) return !B;
        if (!B) return true;
        if (A->val != B->val) return false;
        return equal(A->left, B->left) && equal(A->right, B->right);
    }
    
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        if (A->val == B->val && equal(A, B)) return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
