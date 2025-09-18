class Solution {
public:
    int ans = INT_MAX;
    vector<int> r;
    void solve(vector<int>&factors, vector<int>result, int index, int n,
              int k) {

        if (k == 0) {
            cout<<"hello";
            if (n == 1) {
                int max = *max_element(result.begin(), result.end());
                int min = *min_element(result.begin(), result.end());
                int diff = max - min;
                if (diff < ans) {
                    ans = diff;
                    r = result;
                }
            }
            return;
        }
        for (int i = index; i < factors.size(); i++) {
            if (n % factors[i] == 0) {
                result.push_back(factors[i]);
                solve(factors, result, i, n / factors[i], k-1);
                result.pop_back();
            }
        }
        return;
        
    }
    vector<int> minDifference(int n, int k) {
        vector<int> factors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (i * i != n) {
                    factors.push_back(n / i);
                }
            }
        }
        vector<int> result = {};
        solve(factors, result, 0, n, k);
        return r;
    }
};