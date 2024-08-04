class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int sum = nums[i];
            v.push_back(sum);
            for (int j = i + 1; j < n; j++) {
                sum += nums[j];
                v.push_back(sum);
            }
        }
        cout << v.size();
        sort(v.begin(), v.end());
        long long  s = 0;
        for (int i = left - 1; i < right; i++) {
            s += v[i];
        }
        int mod = (pow(10, 9) + 7);
        return s % mod;
    }
};