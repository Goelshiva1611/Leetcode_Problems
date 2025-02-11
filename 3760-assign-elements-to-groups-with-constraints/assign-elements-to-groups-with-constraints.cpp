class Solution {
public:
    vector<int> assignElements(vector<int>& g, vector<int>& e) {
        int n = g.size();
        int m = e.size();
        map<int, int> map;
        for (int i = 0; i < m; i++) {
            if (map.find(e[i]) == map.end())
                map[e[i]] = i;
        }
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int ans = INT_MAX;
            for (int j = 1; j * j <= g[i]; j++) {
                if (g[i] % j == 0) {
                    if (map.find(j) != map.end())
                        ans = min(ans, map[j]);
                    if (j != g[i] / j && map.find(g[i] / j) != map.end())
                        ans = min(ans, map[g[i] / j]);
                }
            }
            if (ans == INT_MAX)
                ans = -1;
            v.push_back(ans);
        }

        return v;
    }
};

/*
for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i)  // Avoid duplicate when n is a perfect square
                divisors.push_back(n / i);
        }
    }
*/