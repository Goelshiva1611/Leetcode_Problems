class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int n = nums.size();
        priority_queue<long long int> pq;
        long long int score = 0;
        long long int t = n;
        sort(nums.begin(), nums.end());
        long long int p = k;
        while (p != 0 && t!=0) {
            pq.push(nums[t - 1]);
            t--;
            p--;
        }
        for (int i = 0; i < k; i++) {
                long long int a = pq.top();
                score += a;
                pq.pop();
                pq.push(ceil(a * 1.0 / 3 * 1.0));
        }
        return score;
    }
};