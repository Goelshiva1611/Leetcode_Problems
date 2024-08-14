class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int p = *max_element(begin(nums), end(nums));
        vector<int>v(p+1,0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = (abs(nums[i] - nums[j]));
                v[x]++;
            }
        }
        int ans;
        for (int i = 0; i <p+1; i++) {
            k = k - v[i];
            if (k <= 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};