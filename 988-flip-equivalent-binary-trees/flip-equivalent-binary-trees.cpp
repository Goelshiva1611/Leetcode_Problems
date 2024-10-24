class Solution {
public:
    bool levelorder(TreeNode* root1, TreeNode* root2) {
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* dummy1 = new TreeNode(-1);
        queue<pair<TreeNode*, TreeNode*>> qu;
        queue<pair<TreeNode*, TreeNode*>> qu1;
        qu.push({root1, dummy});
        qu1.push({root2, dummy1});
        while (!qu.empty() || !qu1.empty()) {
            int size = qu.size();
            int size1 = qu1.size();
            set<pair<int, int>> v1;
            set<pair<int, int>> v2;
            while (size--) {
                TreeNode* root = qu.front().first;
                TreeNode* parent = qu.front().second;
                qu.pop();
                if (root->left)
                    qu.push({root->left, root});
                if (root->right)
                    qu.push({root->right, root});
                v1.insert({root->val, parent->val});
            }
            while (size1--) {
                TreeNode* root4 = qu1.front().first;
                TreeNode* parent1 = qu1.front().second;
                qu1.pop();
                if (root4->left)
                    qu1.push({root4->left, root4});
                if (root4->right)
                    qu1.push({root4->right, root4});
                v2.insert({root4->val, parent1->val});
            }
            if (v1.size() != v2.size())
                return false;
            if (v1 != v2)
                return false;
        }
        return true;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 != nullptr && root2 != nullptr)
            return levelorder(root1, root2);
        if (root1 == nullptr && root2 == nullptr)
            return true;
        return false;
    }
};