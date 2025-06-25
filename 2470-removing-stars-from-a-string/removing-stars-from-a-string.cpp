class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        int count = 0;
        string answer = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*') {
                count++;
            } else {
                if (count > 0) {

                    count--;

                } else
                    answer.push_back(s[i]);
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};