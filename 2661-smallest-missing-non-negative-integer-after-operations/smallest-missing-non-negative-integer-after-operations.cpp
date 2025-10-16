class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int b = a % value;
            if (b < 0)
                b += value;
            cout << b;
            cout << endl;
            mp[b]++;
        }
        for (int i = 0; i < n; i++) {
            mp[i % value]--;
            if (mp[i%value] < 0) {
                return i;
            }
        }
        return n;
    }
};