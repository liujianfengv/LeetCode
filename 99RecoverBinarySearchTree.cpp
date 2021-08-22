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
    TreeNode *first_node;
    TreeNode *second_node;
    TreeNode *pre_node;
    void recoverTree(TreeNode* root) {
        pre_node = new TreeNode(INT_MIN);
        first_node = nullptr;
        second_node = nullptr;
        recurisveInOrder(root);
        if (first_node && second_node) {
            int tmp = first_node->val;
            first_node->val = second_node->val;
            second_node->val = tmp;
        }
    }
    void recurisveInOrder(TreeNode *root) {
        if (root == nullptr) {
            return ;
        }
        recurisveInOrder(root->left);
        if (first_node == nullptr && root->val < pre_node->val) {
            first_node = pre_node;
        }
        if (first_node && root->val < pre_node->val) {
            second_node = root;
        }
        pre_node = root;
        recurisveInOrder(root->right);
    }
};