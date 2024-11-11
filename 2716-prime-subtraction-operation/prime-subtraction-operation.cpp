class Solution {
public:
    bool isprime(int num) {
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    set<int> findallprime() {
        set<int> st;
        for (int i = 2; i < 1000; i++) {
            if (isprime(i)) {
                st.insert(i);
            }
        }
        st.insert(2);
        return st;
    }
    void seiveprimemethod(vector<bool>& isprimereal) {
        isprimereal[0] = isprimereal[1] = false;
        for (int i = 2; i * i < 1000; i++) {
            if (isprimereal[i] == true) {
                for (int j = 2 * i; j < 1000; j += i) {
                    isprimereal[j] = false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        set<int> st = findallprime();
        vector<bool> isprimereal(1000, true);
        seiveprimemethod(isprimereal);
        for (int i = n - 1; i >= 1; i--) {
            if (nums[i - 1] - nums[i] >= 0) {
                for (int k = 2; k < nums[i - 1]; k++) {
                    if (isprimereal[k] == 1) {
                        int p = nums[i - 1] - k;
                        if (p - nums[i] < 0) {
                            nums[i - 1] = nums[i - 1] - k;
                            break;
                        }
                    }
                }
                if (nums[i - 1] - nums[i] >= 0) {
                    return false;
                }
            }
        }
        return true;
    }
};