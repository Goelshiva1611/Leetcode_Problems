class FindElements {
public:
    set<int> st;
    FindElements(TreeNode* root) {
        queue<pair<TreeNode*, int>> qu;
        qu.push({root, 0});
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                TreeNode* newnode = qu.front().first;
                int value = qu.front().second;
                qu.pop();
                st.insert(value);
                if (newnode->left)
                    qu.push({newnode->left, 2 * value + 1});
                if (newnode->right)
                    qu.push({newnode->right, 2 * value + 2});
            }
        }
    }
    bool find(int target) {
        if (st.find(target) != st.end())
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */