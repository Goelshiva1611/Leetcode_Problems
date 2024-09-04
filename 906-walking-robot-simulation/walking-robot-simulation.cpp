
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int newx = 0;
        int newy = 0;
        int n = commands.size();
        set<pair<int, int>> st;
        vector<int> direction(4, 0);
        direction[0] = 1;
        vector<int> distance;
        for (int i = 0; i < obstacles.size(); i++) {
            st.insert({obstacles[i][0], obstacles[i][1]});
        }
        for (int i = 0; i < n; i++) {
            if (commands[i] >= 1 && commands[i] <= 9) {
                if (direction[0] == 1) { // north
                    for (int j = 0; j < commands[i]; j++) {
                        newy += 1;
                        if (st.find({newx, newy}) != st.end()) {
                            newy = newy - 1;
                            break;
                        }
                    }
                    distance.push_back(newx * newx + newy * newy);
                    continue;
                }
                if (direction[1] == 1) // east
                {
                    for (int j = 0; j < commands[i]; j++) {
                        newx += 1;
                        if (st.find({newx, newy}) != st.end()) {
                            newx = newx - 1;
                            break;
                        }
                    }
                    cout << newx * newx + newy * newy;
                    distance.push_back(newx * newx + newy * newy);
                }
                if (direction[2] == 1) // east
                {
                    for (int j = 0; j < commands[i]; j++) {
                        newy -= 1;
                        if (st.find({newx, newy}) != st.end()) {
                            newy = newy + 1;
                            break;
                        }
                    }
                    distance.push_back(newx * newx + newy * newy);
                    continue;
                }
                if (direction[3] == 1) // east
                {
                    for (int j = 0; j < commands[i]; j++) {
                        newx -= 1;
                        if (st.find({newx, newy}) != st.end()) {
                            newx = newx + 1;
                            break;
                        }
                    }
                    distance.push_back(newx * newx + newy * newy);
                }
            }
            if (commands[i] == -2) {
                for (int i = 0; i < direction.size(); i++) {
                    if (direction[i] == 1) {
                        direction = {0, 0, 0, 0};
                        direction[(i + 3) % 4] = 1;
                        break;
                    }
                }
            }
            if (commands[i] == -1) {
                for (int i = 0; i < direction.size(); i++) {
                    if (direction[i] == 1) {
                        direction = {0, 0, 0, 0};
                        direction[(i + 1) % 4] = 1;
                        break;
                    }
                }
            }
        }
        nth_element(begin(distance), begin(distance) + distance.size() - 1,
                    end(distance));
        return distance[distance.size() - 1];
    }
};