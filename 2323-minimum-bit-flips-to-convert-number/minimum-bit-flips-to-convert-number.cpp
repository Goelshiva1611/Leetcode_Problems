class Solution {
public:
    string dectobin(int num) {
        string ans = "";
        while (num) {
            ans = to_string(num % 2) + ans;
            num /= 2;
        }
        return ans;
    }
    int minBitFlips(int start, int goal) {
        string p = dectobin(start);
        string q = dectobin(goal);
        int count = 0;
        if (p.size() < q.size())
            while (p.size() != q.size())
                p = '0' + p;
        else
            while (p.size() != q.size())
                q = '0' + q;
        for (int i = 0; i < q.size(); i++)
            if (p[i] != q[i])
                count++;
        return count;
    }
};