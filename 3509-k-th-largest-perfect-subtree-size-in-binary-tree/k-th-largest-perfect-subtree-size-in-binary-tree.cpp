/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    pair<int, int> levelorder(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int nodes = 0;
        int level = 0;
        while (!qu.empty()) {
            int size = qu.size();
            nodes += size;
            while (size--) {
                TreeNode* root1 = qu.front();
                qu.pop();
                if (root1->left) {
                    qu.push(root1->left);
                }
                if (root1->right) {
                    qu.push(root1->right);
                }
            }
            level++;
        }
        return {level, nodes};
    }
    void solve(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            v.push_back(1);
            return;
        }
        pair<int, int> p = levelorder(root);
        v.push_back((p.second == pow(2, p.first) - 1) ? p.second:-1);
        solve(root->left);
        solve(root->right);
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        solve(root);
        v.resize(2000,-1);
        sort(v.rbegin(),v.rend());
        return v[k-1];
    }
};