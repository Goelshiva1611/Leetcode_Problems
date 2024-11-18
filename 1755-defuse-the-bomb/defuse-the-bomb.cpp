class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> v;
        vector<int> ans;
        int n = code.size();
        for (int i = 0; i < 3 * code.size(); i++)
            v.push_back(code[i % n]);
        if (k > 0) {
            int sum = 0;
            for (int i = n + 1; i <= n + k; i++)
                sum += v[i];
            for (int i = 0; i < n; i++) {
                ans.push_back(sum);
                sum -= v[n + i + 1];
                sum += v[n + i + k + 1];
            }
        }
        if (k == 0) {
            for (int i = 0; i < n; i++)
                ans.push_back(0);
        }
        if (k < 0) {
            int sum = 0;
            for (int i = n - abs(k); i < n; i++) {
                sum += v[i];
            }
            for (int i = 0; i < n; i++) {
                ans.push_back(sum);
                sum -= v[n - abs(k) + i];
                sum += v[i];
            }
        }
        return ans;
    }
};