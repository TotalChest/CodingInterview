/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* new_node(vector<int>& nums, int l, int r) {
        if (l > r)
            return nullptr;
        int mid = l + (r-l)/2;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left = new_node(nums, l , mid - 1);
        head->right = new_node(nums, mid + 1, r);
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return new_node(nums, 0, nums.size() - 1);
    }
};
