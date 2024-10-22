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
    void levelordertraversal(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            int sum = 0;
            while (size--) {
                TreeNode* root1 = qu.front();
                qu.pop();
                sum += root1->val;
                if (root1->left) {
                    qu.push(root1->left);
                }
                if (root1->right) {
                    qu.push(root1->right);
                }
            }
            v.push_back(sum);
        }
    }
    int maxLevelSum(TreeNode* root) {
        levelordertraversal(root);
        int m = INT_MIN;
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (v[i] > m) {
                ans = i;
                m = v[i];
            }
        }
        return ans + 1;
    }
};