class Solution {
public:
    int n;
    vector<int> v;
    bool solve(int i, int num, vector<int>& nums) {
        if (i == n - 1) {
            return true;
        }
        if (v[i] != -1) {
            return v[i];
        }
        for (int j = 1; j <= num; j++) {
            bool t = solve(i + j, nums[i + j], nums);
            if (t == true) {
                return true;
            }
        }
        return v[i] = false;
    }
    bool canJump(vector<int>& nums) {
        v.clear();
        v.resize(10001, -1);
        n = nums.size();
        return solve(0, nums[0], nums);
    }
};