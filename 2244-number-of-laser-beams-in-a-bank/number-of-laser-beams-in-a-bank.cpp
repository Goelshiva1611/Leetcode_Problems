class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long int ans = 0;
        int c = 0;
        int p = 0;
        for (int i = 0; i < bank[0].size(); i++) {
            if (bank[0][i] == '1')
                c++;
        }
        for (int j = 1; j < bank.size(); j++) {
            string x = bank[j];
            p = 0;
            for (int i = 0; i < x.size(); i++) {
                if (x[i] == '1')
                    p++;
            }
            if (p == 0) {
                continue;
            } else {
                ans += p * c;
                c = p;
            }
        }
        return ans;
    }
};