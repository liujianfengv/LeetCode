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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        for (int i = 1; i <= n; ++i) {
            vector<TreeNode*> subres = findResultVec(i, 1, n);
            res.insert(res.end(), subres.begin(), subres.end());
        }
        return res;
    }
private:
    vector<TreeNode*> findResultVec(int cur, int left, int right) {
        vector<TreeNode*> res;
        if (left == right) {
            res.push_back(new TreeNode(cur));
            return res;
        }
        if (left > right) {
            res.push_back(nullptr);
            return res;
        }
        vector<TreeNode*> leftRes;
        vector<TreeNode*> rightRes;
        if (cur == left) {
            leftRes.push_back(nullptr);
        }
        for (int i = left; i < cur ; ++i) {
            auto subRes = findResultVec(i, left, cur - 1);
            leftRes.insert(leftRes.end(), subRes.begin(), subRes.end());
        }
        if (cur == right) {
            rightRes.push_back(nullptr);
        }
        for (int i = cur + 1; i <= right; ++i) {
            auto subRes = findResultVec(i, cur + 1, right);
            rightRes.insert(rightRes.end(), subRes.begin(), subRes.end());
        }
        for (auto i : leftRes) {
            for (auto j : rightRes) {
                TreeNode *root = new TreeNode(cur);
                root->left = i;
                root->right = j;
                res.push_back(root);
            }
        }
        return res;
    }
};