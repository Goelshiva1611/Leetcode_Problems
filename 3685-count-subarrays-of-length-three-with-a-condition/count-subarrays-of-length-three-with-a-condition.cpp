class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = i + 2;
        int count = 0;
        while (j < n) {
            if ((nums[j] + nums[i]) * 2 == nums[i + 1]) {
                count++;
            }
            i++;
            j++;
        }
        return count;
    }
};