class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += abs(mid - nums[i]);
        }
        return count;
    }
};