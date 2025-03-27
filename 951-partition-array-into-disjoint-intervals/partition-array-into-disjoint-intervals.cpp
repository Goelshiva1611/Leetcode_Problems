class Solution {
public:
    priority_queue<int> maxpq;

    int partitionDisjoint(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minpq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            minpq.push({nums[i], i});
        }
        for (int i = 0; i < n; i++) {
            maxpq.push(nums[i]);
            while (!minpq.empty() && minpq.top().second <= i)
                minpq.pop();
            if (!minpq.empty() && minpq.top().first < maxpq.top()) {
                if (minpq.top().first == nums[i] && minpq.top().second == i)
                    minpq.pop();
            } else
                return i + 1;
        }
        return -1;
    }
};