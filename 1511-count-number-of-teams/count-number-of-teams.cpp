class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int t = 0;
        int count = 1;
        for (int i = 0; i <= n - 3; i++) {
            int p = rating[i]; // 2
            for (int j = i + 1; j <= n - 2; j++) {
                int q = rating[j]; // 5
                if (q > p) {
                    for (int k = j + 1; k <= n - 1; k++) {
                        if (rating[k] > q) {
                            t++;
                        }
                    }
                } else {
                    for (int k = j + 1; k <= n - 1; k++) {
                        if (rating[k] < q) {
                            t++;
                        }
                    }
                }
            }
        }
        return t;
    }
};