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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        queue<TreeNode*> queue_level;
        queue_level.push(root);
        vector<vector<int>> vec_res;
        while(queue_level.size() > 0) {
            vector<int> vec_level;
            queue<TreeNode*> queue_next;
            while (queue_level.size() > 0) {
                vec_level.push_back(queue_level.front()->val);
                if (queue_level.front()->left) {
                    queue_next.push(queue_level.front()->left);
                }
                if (queue_level.front()->right) {
                    queue_next.push(queue_level.front()->right);
                }
                queue_level.pop();
            }
            vec_res.push_back(vec_level);
            queue_level = queue_next;
        }
        return vec_res;
    }
};