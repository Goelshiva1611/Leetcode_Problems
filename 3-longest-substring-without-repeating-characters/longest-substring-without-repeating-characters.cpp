class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int m=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]>1)
            {
                m=max(m,i-j);
                while(mp[s[i]]!=1 && j<=i)
                {
                    mp[s[j]]--;
                    j++;
                }
            }            
        }
        m=max(m,n-j);
        return m;
    }
};