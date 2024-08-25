
class Solution {
public:
    void post(TreeNode* root, vector<int>& p) {
        if (root == nullptr) {
            return;
        }
        post(root->left, p);
        post(root->right, p);
        p.push_back((root->val));
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> p;
        post(root, p);
        return p;
    }
};