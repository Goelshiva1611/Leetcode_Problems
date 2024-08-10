class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += arr[i];
        }
        for (int i = 2; i < n; i = i + 2) {
            int sum = 0;
            for (int j = 0; j <= i; j++) {
                sum += arr[j];
            }
            ans += sum;
            int t = 0;
            cout << ans;
            for (int k = i + 1; k < n; k++) {
                sum = sum + arr[k] - arr[t];
                cout << sum;
                ans += sum;
                t++;
            }
        }
        return ans;
    }
};