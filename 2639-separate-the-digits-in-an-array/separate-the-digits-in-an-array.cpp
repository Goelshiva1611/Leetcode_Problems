class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> separate_digits;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> p;
            while (nums[i]) {
                p.push_back(nums[i] % 10);
                nums[i] /= 10;
            }
            reverse(p.begin(), p.end());
            for (int i = 0; i < p.size(); i++)
                separate_digits.push_back(p[i]);
        }
        return separate_digits;
    }
};