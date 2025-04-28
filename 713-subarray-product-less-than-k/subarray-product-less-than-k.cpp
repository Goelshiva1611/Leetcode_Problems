class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long sum = 1;
        int l = 0;
        long long answer = 0;
        while (j < n) {
            sum *= nums[j];
            // l = j - i + 1;
            while (i<=j && sum >= k) {
                sum = sum / nums[i];
                i++;
                // l = j - i + 1;
            }
            answer += j - i + 1;
            j++;
        }
        return answer;
    }
};