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
        bitset<32>b1(start);
        bitset<32>b2(goal);
        int count=0;
        for (int i = 0; i < b1.size(); i++)
            if (b1[i] != b2[i])
                count++;
        return count;
    }
};