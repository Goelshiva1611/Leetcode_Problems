class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        long long c = 0;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                int left = s.top();
                s.pop();
                if (i - left + 1 >= 3)
                    c++;
            }
            if (!s.empty() && i - s.top() + 1 >= 3) {
                c++;
            }
            s.push(i);
        }
        return c;
    }
};

/*
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        while (i < nums.size() - 2) {
            int j = i + 2;
            int b = INT_MIN;
            while (j < n) {
                int a = min(nums[i], nums[j]);
                b = max(b, nums[j - 1]);
                if (a > b)
                    count++;
                j++;
            }
            i++;
        }
        return count;
    }
};*/