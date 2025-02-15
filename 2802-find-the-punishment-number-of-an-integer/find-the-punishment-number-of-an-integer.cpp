class Solution {
public:
    bool check(int i, int currsum, string s, int num, vector<vector<int>>& t) {
        if (i == s.length()) {
            return currsum == num;
        }
        if (currsum > num)
            return false;

        // if (t[i][currsum] != -1) //we have repeating subproblems. Draw tree
        // diagram of "1296"
        //     return t[i][currsum];

        for (int j = i; j < s.length(); j++) {
            string currentString = s.substr(i, j - i + 1);
            int addend = stoi(currentString);

            if (check(j + 1, currsum + addend, s, num, t) == true)
            {
                return true;
            }
        }

        return false;
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;
        for (int num = 1; num <= n; num++) {
            int squareNum = num * num;
            string s = to_string(squareNum);

            vector<vector<int>> t(s.size(), vector<int>(num + 1, -1));

            if (check(0, 0, s, num, t)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};
