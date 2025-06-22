class Solution {
public:
    int canpossible(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int answer = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                answer = nums.size() - mid;
                high = mid - 1;
            }
        }
        return answer;
    }
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = *max_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int total = canpossible(nums, mid);
            if (total == mid) {
                return total;
            } else if (total < mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};