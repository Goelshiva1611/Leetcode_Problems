class Solution {
public:
    int height(TreeNode* root, vector<int>& g) {
        if (root == nullptr)
            return 0;
        int l = height(root->left, g);
        int r = height(root->right, g);
        int h = max(l, r) + 1;
        g[root->val] = h;
        return h;
    }
    unordered_map<int, int> mp;
    void levelorder(TreeNode* root, set<int> st, vector<int> g) {
        queue<TreeNode*> qu;
        qu.push(root);
        int level = 0;
        while (!qu.empty()) {
            int size = qu.size();
            vector<int> levelnodes;
            int maxi = 0;
            int secondmaxi = 0;
            while (size--) {
                TreeNode* root1 = qu.front();
                qu.pop();
                if (maxi < g[root1->val]) {
                    secondmaxi = maxi;
                    maxi = g[root1->val];
                } else if (secondmaxi < g[root1->val]) {
                    secondmaxi = g[root1->val];
                }
                if (root1->left)
                    qu.push(root1->left);
                if (root1->right)
                    qu.push(root1->right);

                levelnodes.push_back(root1->val);
                
            }
            for (int i = 0; i < levelnodes.size(); i++) {
                if (st.find(levelnodes[i]) != st.end()) {
                    mp[levelnodes[i]] = level + (maxi==g[levelnodes[i]]?secondmaxi:maxi) - 1;
                }
            }
            level++;
        }
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int h = 0, count = 0;
        vector<int> v;
        vector<int> g(100001);
        set<int> st;
        height(root, g);
        for (int j = 0; j < queries.size(); j++)
            st.insert(queries[j]);
        levelorder(root, st, g);
        for (int i = 0; i < queries.size(); i++) {
            v.push_back(mp[queries[i]]);
        }
        return v;
    }
};