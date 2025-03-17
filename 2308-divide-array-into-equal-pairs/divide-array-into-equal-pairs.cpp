class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        if(mp.size()>nums.size()/2)
            return false;
        for (auto it : mp)
            if (it.second % 2 != 0)
                return false;
        return true;
    }
};