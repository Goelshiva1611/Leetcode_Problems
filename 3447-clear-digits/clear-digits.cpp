class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]>=48 && s[i]<=57 && !st.empty())
                st.pop();
            else
                st.push(s[i]);
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};

/*
class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        cout<<p;
        vector<char> v;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 48 && s[i] <= 57) {
                // is digit
                if (v.size() > 0) {
                    v.pop_back();
                }
            } else {
                v.push_back(s[i]);
            }
        }
        string ans = "";
        for (int i = 0; i < v.size(); i++) {
            ans += v[i];
        }
        return ans;
    }
};
*/
/*
class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            (s[i] >= 48 && s[i] <= 57 && ans.size() > 0) ? ans.pop_back()
                                                         : ans.push_back(s[i]);
        }
        return ans;
    }
};
*/
