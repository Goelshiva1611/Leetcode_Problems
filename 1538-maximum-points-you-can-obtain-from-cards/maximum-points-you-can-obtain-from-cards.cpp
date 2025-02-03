class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int j = n - 1;
        int i = k - 1;
        int sum = 0;
        for (int p = 0; p < k; p++) {
            sum += cardPoints[p];
        }
        int m = 0;
        int x = n - 1;
        while (i >= 0) {
            m = max(m, sum);
            cout << m;
            sum -= cardPoints[i];
            sum += cardPoints[x];
            i--;
            x--;
        }
        sum = 0;
        for (int i = n - k; i < n; i++) {
            sum += cardPoints[i];
        }
        m = max(m, sum);
        return m;
    }
};