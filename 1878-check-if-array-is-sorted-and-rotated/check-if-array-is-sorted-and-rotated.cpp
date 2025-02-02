class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> p;
        vector<int> t;
        vector<int> s;
        s = nums;
        sort(s.begin(), s.end());
        int x = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] < 0) {
                p.push_back(nums[i - 1]);
                x = i;
                break;
            }
            p.push_back(nums[i - 1]);
        }
        for (int i = x; i < nums.size(); i++)
            t.push_back(nums[i]);
        if (x != 0) {
            for (int i = 0; i < p.size(); i++)
                t.push_back(p[i]);
        }
        return (t == s) ? true : false;
    }
};

/* bool check(vector<int>& nums) {
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
    }*/