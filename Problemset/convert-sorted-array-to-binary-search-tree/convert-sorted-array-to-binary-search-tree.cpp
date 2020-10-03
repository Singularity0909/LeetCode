
// @Title: 将有序数组转换为二叉搜索树 (Convert Sorted Array to Binary Search Tree)
// @Author: Singularity0909
// @Date: 2020-09-29 10:20:46
// @Runtime: 32 ms
// @Memory: 22.6 MB

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};
