class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long  sum = 0;
        int l = 0;
        long long  answer = 0;
        while (j < n) {
            sum += nums[j];
            l = j - i + 1;
            while (sum * l >= k) {
                sum -= nums[i];
                i++;
                l = j - i + 1;
            }
            answer += j - i + 1;
            j++;
        }
        return answer;
    }
};