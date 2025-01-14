class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        bool flag = false;
        int col = 0;
        while (size > 0) {
            if (flag == false) {
                size -= numRows;
                col++;
            } else {
                size -= abs((numRows - 2));
                col += abs(numRows - 2);
            }
            flag = !flag;
        }
        cout << col;
        vector<vector<char>> v;
        v.resize(numRows, vector<char>(col, '!'));
        bool fl = false;
        int x = 0;
        for (int i = 0; i < col;) {
            if (fl == false) {
                for (int j = 0; j < numRows; j++) {
                    if (x < s.size())
                        v[j][i] = s[x];
                    x++;
                }
                i++;
            } else {
                int t = numRows - 2;
                while (t > 0 && x < s.size()) {
                    cout << x;
                    v[t][i] = s[x];
                    t--;
                    i++;
                    x++;
                }
            }
            fl = !fl;
        }
        string ans;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < col; j++) {
                if (v[i][j] != '!') {
                    ans += v[i][j];
                }
            }
        }
        return ans;
    }
};