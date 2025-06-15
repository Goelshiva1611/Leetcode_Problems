class Solution {
public:
    string generateTag(string caption) {
        string answer = "#";
        int n = caption.size();
        int w = 0;
        for (int i = 0; i < n; i++) {
            if (caption[i] == ' ') {
                if (i + 1 < n && caption[i + 1] != ' ' && w != 0) {
                    if (caption[i + 1] >= 97 && caption[i + 1] <= 122) {
                        answer.push_back(caption[i + 1] - 32);

                    } else {
                        answer.push_back(caption[i + 1]);
                    }

                    i++;
                }
                w++;
            } else {
                if (caption[i] >= 65 && caption[i] <= 91) {
                    answer.push_back(caption[i] + 32);

                } else {
                    answer.push_back(caption[i]);
                }
                w++;
            }
        }
        int p = answer.size();
        int t = min(p, 100);
        string final = answer.substr(0, t);
        return final;
    }
};