
class Solution {
public:
    void levelorder(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> qu;
        TreeNode* dummy = new TreeNode(-1);
        qu.push({root, dummy});
        vector<int> v;
        while (!qu.empty()) {
            int size = qu.size();
            vector<pair<TreeNode*, TreeNode*>> vec;
            int sum = 0;
            while (size--) {
                TreeNode* root1 = qu.front().first;
                TreeNode* root2 = qu.front().second;
                qu.pop();
                sum += root1->val;
                if (root1->left)
                    qu.push({root1->left, root1});
                if (root1->right)
                    qu.push({root1->right, root1});
                vec.push_back({root1, root2});
            }
            for (int i = 0; i < vec.size(); i++) {
                int t = sum;
                TreeNode* parent = vec[i].second;
                if (parent->val == -1) {
                    t = 0;
                    cout << t;
                    v.push_back(t);
                    continue;
                }
                if (parent->left)
                    t = t - parent->left->val;
                if (parent->right)
                    t = t - parent->right->val;
                cout << t;
                v.push_back(t);
            }
        }
        level2order(root, v);
    }
    void level2order(TreeNode* root, vector<int> v) {
        queue<TreeNode*> qu;
        qu.push(root);
        int i = 0;
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                TreeNode* root1 = qu.front();
                qu.pop();
                cout << v[i];
                root1->val = v[i];
                if (root1->left)
                    qu.push(root1->left);
                if (root1->right)
                    qu.push(root1->right);
                i++;
            }
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        levelorder(root);
        return root;
    }
};