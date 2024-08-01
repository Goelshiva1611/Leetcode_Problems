class Solution {
public:
    int countSeniors(vector<string>& details) {

        int n = details.size();
        int t = 0;
        for (int i = 0; i < n; i++) {
            string p = details[i];
            int a = p[11] - '0';
            int b = p[12] - '0';
            int c = (a * 10) + b;
            if (c > 60) {
                t++;
            }
        }
        return t;
    }
};