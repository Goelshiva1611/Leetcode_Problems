class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int t=0;
        if(s.size()<k)
        {
            return false;
        }
        for(auto it:mp)
        {
            if(mp[it.first]%2!=0)
            {
                t++;
            }
        }
        if(t>k)
        {
            return false;
        }
        return true;
    }
};