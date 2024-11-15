class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int p = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] < arr[i]) {
                p = i;
                break;
            }
        }
        int q = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (arr[i - 1] > arr[i]) {
                q = i;
                break;
            }
        }
        int m = INT_MAX;
        for (int i = p; i >= 0; i--) {
            for (int j = n - 1; j >= q; j--) {
                if (arr[i] > arr[j]) {
                    m = min(m, j - i);
                    cout << m;
                    break;
                }
            }
        }
        for (int i = q; i < n; i++) {
            for (int j = 0; j <= p; j++) {
                if (arr[j] > arr[i]) {
                    m = min(m, i - j);
                    cout << m;
                    break;
                }
            }
        }
        if (m == INT_MAX) {
            return (q - p - 1 < 0) ? 0 : q - p - 1;
        }

        return m;
    }
};