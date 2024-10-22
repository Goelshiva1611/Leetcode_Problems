
class Solution {
public:
    vector<long long> v;
    void levelorder(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        long long int sum = 0;
        while (!qu.empty()) {
            int size = qu.size();
            cout << size;
            sum = 0;
            while (size != 0) {
                TreeNode* root1 = qu.front();
                qu.pop();
                sum += root1->val;
                if (root1->left)
                    qu.push(root1->left);
                if (root1->right)
                    qu.push(root1->right);
                size--;
            }
            v.push_back(sum);
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        levelorder(root);
        sort(v.rbegin(), v.rend());
        if (v.size() < k)
            return -1;
        return v[k - 1];
    }
};