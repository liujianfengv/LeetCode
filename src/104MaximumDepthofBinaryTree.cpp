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
    int maxDepth(TreeNode* root) {
        return countDepth(root, 0);
    }
private:
    int countDepth(TreeNode *root, int count) {
        if (root) {
            count++;
        } else {
            return 0;
        }
        int leftDepth = countDepth(root->left, 0);
        int rightDepth = countDepth(root->right, 0);
        return count + max(leftDepth, rightDepth);
    }
    
};