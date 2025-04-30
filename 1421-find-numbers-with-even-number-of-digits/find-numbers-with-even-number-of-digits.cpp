class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
            count += (to_string(nums[i]).size() % 2 == 0) ? 1 : 0;
        return count;
    }
};
