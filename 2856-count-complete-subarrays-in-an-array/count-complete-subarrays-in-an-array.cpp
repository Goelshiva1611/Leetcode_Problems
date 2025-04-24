class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int dist = mp.size();
        int answer = 0;
        unordered_map<int, int> mp2;
        while (j < n) {
            while (j < n && mp2.size() != dist) {
                mp2[nums[j]]++;
                j++;
            }
            if (j == n && mp2.size() != dist)
                break;
            answer += n - j + 1;
            mp2[nums[i]]--;
            if (mp2[nums[i]] == 0)
                mp2.erase(nums[i]);
            i++;
        }
        bool flag = true;
        while (i < j && mp2.size() == dist) {
            mp2[nums[i]]--;
            if (mp2[nums[i]] == 0) {
                mp2.erase(nums[i]);
            }
            i++;
            answer += 1;
            flag = false;
        }
        return answer;
    }
};