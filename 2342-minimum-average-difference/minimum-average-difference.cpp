class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long int sum = nums[0];
        vector<long long  int> t;
        vector<long long  int> average;
        average.push_back(sum);
        long long  int totalsum = sum;
        for (int i = 1; i < n; i++) {
            sum += nums[i];
            average.push_back(sum / (i + 1));
        }
        long long int m = 0;
        for (int i = 0; i < n; i++) {
            sum -= nums[i];
            int p = 0;
            if ((n - i - 1) != 0) {
                p = sum / (n - i - 1);
                t.push_back(abs(average[i] - p));
                continue;
            }
            t.push_back(abs(average[i] - p));
        }
        long long  int x = 0;
        long long  int q = INT_MAX;
        for (int i = 0; i < n; i++) {
            cout << t[i];
            if (q > t[i]) {
                q = t[i];
                x = i;
            }
        }
        return x;
    }
};