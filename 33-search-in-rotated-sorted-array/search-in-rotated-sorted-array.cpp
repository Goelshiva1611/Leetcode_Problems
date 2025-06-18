class Solution {
public:
    int t = 0;
    int binarysearch(vector<int>& nums, int l, int h) {
        int low = l;
        int high = h;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > t) {
                high = mid - 1;
            } else if (nums[mid] < t) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    int find_pivot(vector<int>& nums) {
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
        return high;
    }
    int search(vector<int>& nums, int target) {
        t = target;
        int pivot_index = find_pivot(nums);
        cout << pivot_index;
        if (binarysearch(nums, 0, pivot_index - 1) == -1) {
            if (binarysearch(nums, pivot_index, nums.size() - 1) == -1) {
                return -1;
            } else {
                return binarysearch(nums, pivot_index, nums.size() - 1);
            }
        }
        return binarysearch(nums, 0, pivot_index - 1);
    }
};