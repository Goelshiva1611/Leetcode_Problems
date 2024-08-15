class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int a = 0;
        int b = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                a++; // 8
            }
            if (bills[i] == 10) {
                b++; // 1
                if (a > 0) {
                    a--;
                }
                else
                {
                    return false;
                }
            }
            if (bills[i] == 20) {
                c++;
                if (a <= 0) {
                    return false;
                }

                if (b <= 0) {
                    if (a >= 3) {
                        a=a-3;
                    }
                    else
                    {
                        return false;
                    }
                }
                if(b>0)
                {
                    a--;
                    b--;
                }
            }
        }

        return true;
    }
};