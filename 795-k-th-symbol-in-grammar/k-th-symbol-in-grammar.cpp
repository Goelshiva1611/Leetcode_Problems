class Solution {
public:
    int kthGrammar(int n, int k) {
        int length = pow(2, n - 1);
        if (n == 1) {
            return 0;
        }
        if (k <= length / 2) {
            return kthGrammar(n - 1, k);
        } else {
            int t = kthGrammar(n - 1, k - (length / 2));
            if (t == 0)
                return 1;
            else
                return 0;
        }
    }
};