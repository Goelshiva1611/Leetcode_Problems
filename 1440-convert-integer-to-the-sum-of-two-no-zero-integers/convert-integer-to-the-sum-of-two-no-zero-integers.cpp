class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> answer;
        int t = n;
        while (true) {
            n--;
            int p = n;
            bool flag = false;
            while (p != 0) {
                int rem = p % 10;
                if (rem == 0) {
                    flag = true;
                    break;
                }
                p = p / 10;
            }
            if (flag == false) {

                int x = t - n;
                bool f = true;
                while (x != 0) {
                    int rem = x % 10;
                    if (rem == 0) {
                        f = false;
                        break;
                    }
                    x = x / 10;
                }
                if (f == true)
                    return {n, t - n};
            }
        }
        return {};
    }
};