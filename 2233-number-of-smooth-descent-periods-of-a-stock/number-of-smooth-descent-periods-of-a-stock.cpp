class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        long long sum = 0;
        int l = 0;
        long long answer = 0;
        while (j < n) {
            sum = nums[j - 1] - nums[j];
            if (sum != 1) {
                i = j;
            }
            answer += j - i + 1;
            j++;
        }
        return answer + 1;
    }
};