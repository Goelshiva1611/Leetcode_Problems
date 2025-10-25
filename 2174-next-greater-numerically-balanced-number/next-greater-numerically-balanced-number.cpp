class Solution {
public:
    vector<int> v;
    int backtrack(int n, int curr, int digleft) {
        if (digleft == 0) {
            for (int i = 1; i < 10; i++) {
                if (v[i] != 0 && v[i] != i) {
                    return 0;
                }
            }
            return curr > n ? curr : 0;
        }
        int result = 0;
        for (int i = 1; i <= 9; i++) {
            if (v[i] > 0 && digleft >= v[i]) {
                v[i]--;
                result = backtrack(n, curr * 10 + i, digleft - 1);
                v[i]++;
            }
            if (result != 0) {
                break;
            }
        }
        return result;
    }
    int nextBeautifulNumber(int n) {
        v.resize(10, 0);
        for (int i = 0; i < 10; i++) {
            v[i] = i;
        }
        string p = to_string(n);
        int ans = backtrack(n, 0, p.size());
        if (ans == 0) {
            return backtrack(n, 0, p.size() + 1);
        }
        return ans;
    }
};