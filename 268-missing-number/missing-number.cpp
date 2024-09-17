class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> v;
        for (int i = 0; i <= nums.size(); i++)
            v.push_back(i);
        return abs(accumulate(nums.begin(), nums.end(), 0)  - accumulate(v.begin(), v.end(), 0));
    }
};