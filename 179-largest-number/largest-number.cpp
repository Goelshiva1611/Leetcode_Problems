class Solution {
public:
    static bool cmp(string& s1, string& s2) { return s1 + s2 > s2 + s1; }
    string largestNumber(vector<int>& nums) {
        string s;
        vector<string> v;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            v.push_back(to_string(nums[i]));
        sort(v.begin(), v.end(), cmp);
        if (v[0] == "0")
            return "0";
        for (int i = 0; i < n; i++)
            s += v[i];
        return s;
    }
};