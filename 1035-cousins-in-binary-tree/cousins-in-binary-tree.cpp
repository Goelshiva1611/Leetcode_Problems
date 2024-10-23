class Solution {
public:
    int q = 0;
    int q1 = 0;
    int l = 0;
    int l1 = 0;
    void dfs(TreeNode* root, int parent, int x, int y, int lev, int lev2) {
        if (root == nullptr)
            return;
        if (root->val == x) {
            q = parent;
            l = lev;
        }
        if (root->val == y) {
            q1 = parent;
            l1 = lev2;
        }
        dfs(root->left, root->val, x, y, lev + 1, lev2 + 1);
        dfs(root->right, root->val, x, y, lev + 1, lev2 + 1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, -1, x, y, 0, 0);
        if (l != l1 || q == q1) 
            return false;
        return true;
    }
};