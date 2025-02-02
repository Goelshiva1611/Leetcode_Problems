class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> x = nums;
        sort(x.begin(), x.end());
        vector<int> p(2 * x.size(), 0);
        for (int i = 0; i < 2 * x.size(); i++) {
            p[i] = nums[i % nums.size()];
        }
        int k = 0;
        int l = nums.size() - 1;
        queue<int> qu;
        queue<int> qu1;
        for (int i = 0; i < nums.size(); i++) {
            qu.push(nums[i]);
        }
        for (int i = 0; i < x.size(); i++) {
            qu1.push(x[i]);
        }
        while (l < 2 * nums.size()) {
            if (qu == qu1) {
                return true;
            }
            l++;
            qu.pop();
            if (l < 2 * nums.size())
                qu.push(p[l]);
        }
        return false;
    }
};