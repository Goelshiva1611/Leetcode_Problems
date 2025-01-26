class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> online;
        sort(events.begin(), events.end(),
             [&](vector<string>& a, vector<string>& b) {
                 if (a[1] == b[1]) {
                     int x = a[0][0];
                     int y = b[0][0];
                     return (x > y);
                 }
                 return stoi(a[1]) < stoi(b[1]);
             });
        for (int i = 0; i < events.size(); i++) {
            cout << events[i][0];
        }
        for (int i = 0; i < numberOfUsers; i++) {
            online.push_back(1);
        }
        queue<pair<int, int>> offline;
        for (int i = 0; i < events.size(); i++) {
            vector<string> p = events[i];
            int time = stoi(p[1]);
            if (!offline.empty()) {
                while (!offline.empty() &&
                       time - offline.front().second >= 60) {
                    int x = offline.front().first;
                    offline.pop();
                    online[x] = 1;
                }
            }
            if (p[0] == "MESSAGE") {

                if (p[2] == "ALL") {
                    for (int q = 0; q < numberOfUsers; q++) {
                        mentions[q]++;
                    }
                } else if (p[2] == "HERE") {
                    for (int q = 0; q < online.size(); q++) {
                        if (online[q] == 1) {
                            mentions[q]++;
                        }
                    }
                } else {
                    int t = 0;
                    for (int l = 2; l < p[2].size();) {
                        int q = p[2][l] - '0';
                        while (l + 1 < p[2].size() && p[2][l + 1] != ' ') {
                            q = q * 10 + (p[2][l + 1] - '0');
                            l++;
                        }
                        mentions[q]++;
                        l += 4;
                    }
                }
            } else {
                offline.push({stoi(p[2]), stoi(p[1])});
                online[stoi(p[2])] = 0;
            }
        }
        return mentions;
    }
};