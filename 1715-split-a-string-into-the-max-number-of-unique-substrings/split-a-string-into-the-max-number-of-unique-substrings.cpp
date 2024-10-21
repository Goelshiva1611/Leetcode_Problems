class Solution {
public:

    void solve(unordered_set<string>st,int i,int &maxcount,int currcount,string s)
    {
        if(currcount+(s.size()-i)<=maxcount)
        {
            return;
        }
        if(i>=s.length())        
        {
            maxcount=max(maxcount,currcount);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            string sub=s.substr(i,j-i+1);
            if(st.find(sub)==st.end())
            {
                st.insert(sub);
                solve(st,j+1,maxcount,currcount+1,s);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int maxcount=0;
        unordered_set<string>st;
        solve(st,0,maxcount,0,s);
        return maxcount;
    }
};