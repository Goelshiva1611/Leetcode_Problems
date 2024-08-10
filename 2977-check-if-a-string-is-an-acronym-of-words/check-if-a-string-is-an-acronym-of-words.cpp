class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string t;
        string st;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            string t =words[i];
            st+=t[0];
        }
        if(s==st)
            return true;

        return false;
    }
};