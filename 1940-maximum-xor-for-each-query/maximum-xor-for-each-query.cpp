class Solution {
public:
    int binary(int a, int maximumBit) {
        string s;
        while (a) {
            int p = a % 2;
            if (p == 1) {
                s += '1';

            } else {
                s += '0';
            }
            a = a / 2;
        }

        while (s.size() != maximumBit) {
            s += '0';
        }
        int ans = 0;
        cout << s;
        cout << endl;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                ans += pow(2, i);
            }
        }
        return ans;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> v;
        int x = nums[0];
        int y = 0;
        v.push_back(binary(x, maximumBit));
        for (int i = 1; i < n; i++) {
            y = nums[i] ^ x;
            x = y;
            v.push_back(binary(y, maximumBit));
        }
        reverse(v.begin(), v.end());
        return v;
    }
};