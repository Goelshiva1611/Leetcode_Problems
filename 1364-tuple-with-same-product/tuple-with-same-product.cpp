class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i + 1; j < n; j++) {
                prod = nums[i] * nums[j];
                mp[prod].push_back(nums[i]);
                mp[prod].push_back(nums[j]);
            }
        }
        int tup = 0;
        for (auto it : mp) {
            int size = it.second.size() / 2;
            if (size < 2) {
                continue;
            }
            cout << size;
            tup += (4 * size * (size - 1));
        }
        return tup;
    }
};

/*
simple brute force
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i + 1; j < n; j++) {
                prod = nums[i] * nums[j];
                mp[prod].push_back(nums[i]);
                mp[prod].push_back(nums[j]);
            }
        }
        int tup=0;
        for(auto it:mp)
        {
            int size=it.second.size()/2;
            if(size<2)
            {
                continue;
            }
            cout<<size;
            tup+=(4*size*(size-1));
        }
        return tup;
    }
};
*/