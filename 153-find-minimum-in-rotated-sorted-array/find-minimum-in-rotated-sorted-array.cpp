class Solution {
public:
    int binarysearcrh(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[high];
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();
        return binarysearcrh(nums);
    }
};