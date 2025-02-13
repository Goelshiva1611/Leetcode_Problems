class Solution {
public:
    typedef priority_queue<double> pp;
    int halveArray(vector<int>& nums) {
        pp pq(nums.begin(), nums.end());
        double sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        double t = sum;
        while (!pq.empty()) {
            double a = pq.top();
            pq.pop();
            double b = a / 2;
            pq.push(b);
            count++;
            sum -= b;
            if (sum <= t / 2)
                return count;
        }
        return count;
    }
};