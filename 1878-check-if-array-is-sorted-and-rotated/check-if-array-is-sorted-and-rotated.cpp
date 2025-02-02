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

/* bool check(vector<int>& nums) {
        int dec = 0;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] < 0) {
                dec++;
                if (dec > 1 || (nums[i]) != sorted[0] ||
                    nums[i - 1] != sorted[sorted.size() - 1])
                    return false;
            }
        }
        return true;
    }*/
/* */

/*
bool check(vector<int>& nums) {
    vector<int> p; // p left of nums
    vector<int> t; // t right of nums till decreasing
    vector<int> s; // sorted
    s = nums;
    // right+left==sortes then true;
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
*/