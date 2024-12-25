class Solution {
public:
    vector<int> levelorder(TreeNode* root) {
        vector<int>v;
        queue<TreeNode*> qu;
        qu.push(root);
        int m = INT_MIN;
        while (!qu.empty()) {
            int size = qu.size();
            m = INT_MIN;
            while (size--) {
                TreeNode* first = qu.front();
                qu.pop();
                if (first->left!=nullptr) {
                    qu.push(first->left);
                }
                if (first->right!=nullptr) {
                    qu.push(first->right);
                }
                if (m <= first->val) {
                    m = first->val;
                }
            }
            v.push_back(m);
        }
        return v;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
        {
            return {};
        }
        ans = levelorder(root);
        return ans;
    }
};