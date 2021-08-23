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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec_res;
        if (root == nullptr) {
            return vec_res;
        }
        stack<TreeNode*> stack_level;
        stack_level.push(root);
        bool left_to_right = true;
        while (stack_level.size() > 0) {
            stack<TreeNode*> stack_tmp;
            vector<int> vec_level;
            while (stack_level.size() > 0) {
                auto node = stack_level.top();
                vec_level.push_back(node->val);
                if (left_to_right) {
                    if (node->left) {
                        stack_tmp.push(node->left);
                    }
                    if (node->right) {
                        stack_tmp.push(node->right);
                    }
                } else {
                    if (node->right) {
                        stack_tmp.push(node->right);
                    }
                    if (node->left) {
                        stack_tmp.push(node->left);
                    }
                }
                stack_level.pop();
            }
            stack_level = stack_tmp;
            left_to_right = !left_to_right;
            vec_res.push_back(vec_level);
        }
        return vec_res;
    }
};