class Solution {
public:
    int height(TreeNode* root, vector<int>& g) {
        if (root == nullptr)
            return 0;
        return g[root->val] =
                   max(height(root->left, g), height(root->right, g)) + 1;
    }
    unordered_map<int, int> mp;
    void levelorder(TreeNode* root, set<int> st, vector<int> g) {
        queue<TreeNode*> qu;
        qu.push(root);
        int level = 0;
        while (!qu.empty()) {
            int maxi = 0;
            int secondmaxi = 0;
            int size = qu.size();
            vector<int> levelnodes;
            vector<int> lheight;
            while (size--) {
                TreeNode* root1 = qu.front();
                qu.pop();
                maxi = max(maxi, g[root1->val]);
                if (root1->left)
                    qu.push(root1->left);
                if (root1->right)
                    qu.push(root1->right);

                levelnodes.push_back(root1->val);
                lheight.push_back(g[root1->val]);
            }
            int c = 0;
            for (int i = 0; i < lheight.size(); i++) {
                if (maxi == lheight[i]) {
                    c++;
                }
                if (lheight[i] > secondmaxi && lheight[i] != maxi) {
                    secondmaxi = lheight[i];
                }
            }

            if (c > 1)
                secondmaxi = maxi;

            for (int i = 0; i < levelnodes.size(); i++)
                if (st.find(levelnodes[i]) != st.end())
                    mp[levelnodes[i]] =
                        level + (maxi == g[levelnodes[i]] ? secondmaxi : maxi) -
                        1;
            level++;
        }
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        set<int> st;
        vector<int> g(100001);
        int h = 0, count = 0;
        height(root, g);
        for (int j = 0; j < queries.size(); j++)
            st.insert(queries[j]);
        levelorder(root, st, g);
        for (int i = 0; i < queries.size(); i++)
            v.push_back(mp[queries[i]]);
        return v;
    }
};