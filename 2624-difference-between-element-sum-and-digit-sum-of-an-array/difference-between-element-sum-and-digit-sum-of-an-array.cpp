class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int sum2=0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 9) {
                sum2 = sum2 + nums[i];
            } else {
                int number = nums[i];
                while (number != 0) {
                    sum2 = sum2 + (number % 10);
                    number = number / 10;
                }
            }
        }
        return abs(sum2 - sum);
    }
};