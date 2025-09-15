class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int> v;
        for(int i : nums){
            for(int j : v) i = min(i,i^j);
            if(i) v.push_back(i);
        }
        int ans = 0;
        for(int i:v) ans = max(ans,ans^i);
        return ans;
    }
};