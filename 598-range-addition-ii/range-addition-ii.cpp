class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0)
            return m * n;
        int a = ops[0][0], b = ops[0][1], result = a * b;
        for (int i = 1; i < ops.size(); i++) {
            a = min(ops[i][0], a);
            b = min(ops[i][1], b);
            result = min(result, a * b);
        }
        return result;
    }
};