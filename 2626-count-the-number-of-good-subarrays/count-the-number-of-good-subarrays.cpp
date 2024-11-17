class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int count = 0;
        long long  ans = 0;
        unordered_map<int, int> mp;
        while (j < nums.size()) {
            mp[nums[j]]++;
            count += mp[nums[j]] - 1;
            cout << count;
            cout<<endl;
            while (count >= k && i < j) {
                ans += (nums.size() - j);
                count -= mp[nums[i]] - 1;
                cout<<count;
                mp[nums[i]]--;
                i++;
            }
             j++;
        }
        return ans;
       
    }

    
};