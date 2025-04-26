class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int count = 0;
        int minp = -1;
        int maxp = -1;
        int culp = -1;
        long long  answer = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxK || nums[i] < minK) {
                culp = i;
            }
            if (nums[i] == minK)
                minp = i;

            if (nums[i] == maxK)
                maxp = i;
            int t = (min(minp, maxp) - culp);
            cout<<t;
            if (t >= 0)
                answer += t;
        }
        return answer;
    }
};