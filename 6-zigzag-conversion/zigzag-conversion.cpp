class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> st(numRows, "");
        int count = 0;
        int n = numRows;
        while (count < s.size()) {
            for (int i = 0; i < n; i++) {
                if(count==s.size())
                    break;
                st[i]=st[i]+s[count];
                count++;
            }
            for (int i = n - 2; i > 0; i--) {
                if(count==s.size())
                    break;
                st[i] = st[i]+s[count];
                count++;
            }
        }
        string ans="";
        for (int i = 0; i <n; i++) {
            ans += st[i];
        }
        return ans;
    }
};