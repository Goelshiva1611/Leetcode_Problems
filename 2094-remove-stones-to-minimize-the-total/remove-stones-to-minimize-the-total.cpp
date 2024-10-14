class Solution {
public:
    int minStoneSum(vector<int>& nums, int k) {
        long long int n = nums.size();
        priority_queue<long long int> pq;
        long long int score = 0;
        long long int t = n;
        long long int p = k;
        while (t!=0) {
            pq.push(nums[t - 1]);
            t--;
        }
        for (int i = 0; i < k; i++) {
                long long int a = pq.top();
                pq.pop();
                pq.push(a-floor(a * 1.0 / 2 * 1.0));
        }
        while(!pq.empty())
        {
            score+=pq.top();
            pq.pop();
        }
        return score;
        
    }
};
