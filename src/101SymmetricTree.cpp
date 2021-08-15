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
    bool isSymmetric(TreeNode* root) {
        return isSymmetricImp(root->left, root->right);
    }
private:
    bool isSymmetricImp(TreeNode *left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }
        if (left && right && left->val == right->val){
            return isSymmetricImp(left->left, right->right) && isSymmetricImp(left->right, right->left);
        } else {
            return false;
        }
    }
};