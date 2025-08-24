class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int ans = INT_MIN;
        int prevones = 0;
        while (i < n) {
            // int curr = nums[i];
            if (nums[i] == 0) {
                ans = max(ans, prevones);
                // cout<<prevones;
                int t = 0;
                while (i<n && nums[i] == 0) {
                    t++;
                    i++;
                }
                if (t != 1) {
                    prevones = 0;
                } else {
                    // cout<<prevones;
                    int afterones = 0;
                    while (i < n && nums[i] == 1) {
                        afterones++;
                        i++;
                    }
                    ans = max(ans, afterones + prevones);
                    prevones = afterones;
                }               
            } else {
                prevones++;
                i++;
            }
        }
        ans = max(ans, prevones);
        if(ans==nums.size())
        {
            return ans-1;
        }
        return ans;
    }
};