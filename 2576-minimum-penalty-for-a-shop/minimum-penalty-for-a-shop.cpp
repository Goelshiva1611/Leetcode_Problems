class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            char a = customers[i];
            if (a == 'Y')
                c++;
        }
        int prevo = 0;
        int prevc = 0;
        int ans = INT_MAX;
        int prevans = ans;
        int p = 0;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, c - prevc + prevo);
            if (ans < prevans) {
                p = i;
                prevans = ans;
            }
            if (i < n && customers[i] == 'Y') {
                prevc++;
            } else {
                prevo++;
            }
        }
        return p;
    }
};