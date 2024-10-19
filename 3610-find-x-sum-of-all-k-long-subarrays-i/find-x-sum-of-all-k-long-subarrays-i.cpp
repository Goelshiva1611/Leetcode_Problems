class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int i = 0;
        int w = x;
        int j = k - 1;
        int sum = 0;
        unordered_map<int, int> mp;
        for (int q = i; q <= j; q++) {
            sum += nums[q];
            mp[nums[q]]++;
        }
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        while (j < n) {
            for (auto& it : mp) {
                pq.push({it.second, it.first});
            }
            if (mp.size() < x) {
                ans.push_back(sum);
            } else {
                int t = 0;
                while (!pq.empty() && w != 0) {
                    t += pq.top().first * pq.top().second;
                    pq.pop();
                    w--;
                }
                ans.push_back(t);
            }
            mp[nums[i]]--;
            sum -= nums[i];
            cout << sum;
            i++;
            j++;
            if (j < n) {
                sum += nums[j];
                mp[nums[j]]++;
            }
            priority_queue<pair<int, int>> tq;
            pq = tq;
            w = x;
        }
        return ans;
    }
};