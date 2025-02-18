class Solution {
public:
    string smallestNumber(string s) {
        int n = s.size();
        queue<pair<int, int>> qu;
        for (int i = 0; i < n;) {
            if (s[i] == 'D') {
                int j = i;
                while (i < n && s[i] != 'I') {
                    i++;
                }
                qu.push({j, i - j});
                continue;
            }
            i++;
        }
        int p = 1;
        string ans = "";
        int x=0;
        while (!qu.empty()) {
            int a = qu.front().first;
            int b = qu.front().second;
            for (int i = ans.size(); i < a; i++) {
                ans += to_string(p);
                p++;
            }
            p+=b;
            x=p;
            for(int i=a;i<=a+b;i++)
            {
                ans += to_string(x);
                x--;             
            }
            qu.pop();
            p++;
        }
        if(ans.size()==n+1)
        {
            return ans;
        }
        while(ans.size()<=n)
        {
            ans+=to_string(p);
            p++;
        }
        return ans;
    }
};