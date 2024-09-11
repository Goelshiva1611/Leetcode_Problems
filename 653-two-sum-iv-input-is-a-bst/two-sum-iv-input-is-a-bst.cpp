
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        preorder(root, v);
        sort(v.begin(), v.end());
        int n = v.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i] + v[j] == k) {
                    return true;
                }
            }
        }
        return false;
    }
};