class Solution {
public:
    typedef priority_queue<long long , vector<long long >, greater<long long >> pp;
    typedef vector<int> vv;
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        pp pq;
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }
        int count = 0;
        while (pq.size() >= 2) {
            if (pq.top() >= k) {
                return count;
            }
            long long  x = pq.top();
            pq.pop();
            long long  y = pq.top();
            pq.pop();
            pq.push(min(x, y) * 2 + max(x, y));
            count++;
            
        }
        return count;
    }
};