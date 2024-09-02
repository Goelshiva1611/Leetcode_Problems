class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long int sum = 0;
        int ans=0;
        for (int i = 0; i < n; i++) {
            sum += chalk[i];
        }
        if (k % sum == 0) {
            return 0;
        } else {
            int t = k / sum;
            sum = sum * t;
            k = k - sum;
            for (int i = 0; i < n; i++) {
                if (k - chalk[i] < 0) {
                    ans = i;
                    break;
                }
                k = k - chalk[i];
            }
        }
        return ans;
    }
};