class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > n / 2) {
                flag = true;
            }
        }
        if (flag == false) {
            return -1;
        }
        unordered_map<int, int> mp1;

        for (int i = 0; i < n; i++) {
            mp1[nums[i]]++;
            if (mp[nums[i]] > n / 2) {
                int p = i;
                int size1 = i + 1;
                int size2 = n - i - 1;
                int freq = mp[nums[i]];
                int freq2 = mp1[nums[i]];
                int freq1 = abs(freq - freq2);
                if (freq1 * 2 > size2 && freq2 * 2 > size1) {
                    return i;
                }
            }
        }
        return -1;
    }
};