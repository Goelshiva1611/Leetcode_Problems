class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        int t = 0;
        int m = grid[0].size(); // column size;
        for (int i = 0; i < n / 2; i++) {
            count = 0;
            for (int j = 0; j < m / 2; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
                if (grid[i][m - j - 1] == 1) {
                    count++;
                }
                if (grid[n - i - 1][j] == 1) {
                    count++;
                }
                if (grid[n - i - 1][m - j - 1] == 1) {
                    count++;
                }
                cout<<count;

                if (count % 4 != 0) {
                    if (count == 1 || count == 3) {
                        t++;
                    }
                    if (count == 2) {
                        t =t+ 2;
                    }
                }
                count=0;
            }
        }
        cout << t;
        int changes = 0;
        int c = 0;
        if (n % 2 == 1) {
            for (int i = 0; i < m / 2; i++) {
                if (grid[n / 2][i] != grid[n / 2][m - i - 1]) {
                    t++;
                    changes++;
                } else {
                    if (grid[n / 2][i] == 1 && grid[n / 2][m - i - 1] == 1)
                        c = c + 2;
                }
            }
        }
        if (m % 2 == 1) {
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][m / 2] != grid[n - i - 1][m / 2]) {
                    t++;
                    changes++;
                } else {
                    if (grid[i][m / 2] == 1 && grid[n-i-1][m/2]==1)
                        c = c + 2;
                }
            }
        }
        if (m % 2 == 1 && n % 2 == 1 && grid[n / 2][m / 2] == 1) {
            t++;
        }
        if (c % 4 == 2) {
            if (changes == 0) {
                t = t + 2;
            }
        }
        return t;
    }
};