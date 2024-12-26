class Solution {
public:
    int countnumber(vector<int>& v) {
        vector<int> sorted(v.begin(), v.end());
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < v.size(); i++) {
            mp[v[i]] = i;
        }
        int swaps = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != sorted[i]) {
                int index=mp[sorted[i]];
                mp[v[i]] = index;
                mp[sorted[i]] = i;
                swap(v[i], v[index]);
                swaps++;
            }
        }
        return swaps;
    }
    int level(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int opt = 0;
        while (!qu.empty()) {
            int size = qu.size();
            vector<int> v;
            while (size--) {
                TreeNode* first = qu.front();
                qu.pop();
                v.push_back(first->val);
                if (first->left)
                    qu.push(first->left);
                if (first->right)
                    qu.push(first->right);
            }
            opt += countnumber(v);
        }
        return opt;
    }
    int minimumOperations(TreeNode* root) { return level(root); }
};