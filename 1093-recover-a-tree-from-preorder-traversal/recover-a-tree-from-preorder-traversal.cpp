class Solution {
public:
    int n;

    void solve(TreeNode*& root, const string& traversal, int& i, int depth) {
        if (i >= n)
            return;
        int dash = 0;
        while (i < n && traversal[i] == '-') {
            dash++;
            i++;
        }
        if (depth != dash) {
            i -= dash;
            return;
        }
        int value = 0;
        string p = "";
        while (i < n && traversal[i] != '-') {
            p += traversal[i];
            i++;
        }
        value = stoi(p);
        root = new TreeNode(value);
        solve(root->left, traversal, i, depth + 1);
        solve(root->right, traversal, i, depth + 1);
    }

    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.length();
        int i = 0;
        TreeNode* newnode = new TreeNode(0);
        solve(newnode->left, traversal, i, 0);
        return newnode->left;
    }
};
