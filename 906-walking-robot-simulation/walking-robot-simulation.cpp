
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        set<pair<int, int>> st;
        for (int i = 0; i < obstacles.size(); i++) {
            st.insert({obstacles[i][0], obstacles[i][1]});
        }
        vector<int> direction(4, 0);
        direction[0] = 1;
        int newx = 0;
        int newy = 0;
        vector<int> distance;
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
                    cout << "T";
                    distance.push_back(newx * newx + newy * newy);
                    continue;
                }
                if (direction[1] == 1) // east
                {
                    cout << "xscdcdcdcd";
                    for (int j = 0; j < commands[i]; j++) {
                        newx += 1;
                        if (st.find({newx, newy}) != st.end()) {
                            newx = newx - 1;
                            cout << "heheheh";
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
                        cout << "jhjfkj";
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
            cout << "jcdk";
            if (commands[i] == -2) {
                if (direction[0] == 1) {
                    direction[0] = 0;
                    direction[3] = 1;
                    continue;
                }
                if (direction[3] == 1) {
                    direction[3] = 0;
                    direction[2] = 1;
                    continue;
                }
                if (direction[2] == 1) {
                    direction[2] = 0;

                    direction[1] = 1;
                    continue;
                }
                if (direction[1] == 1) {
                    direction[1] = 0;
                    direction[0] = 1;
                    continue;
                }
            }
            if (commands[i] == -1) {
                cout << "d";
                if (direction[0] == 1) {
                    direction[0] = 0;
                    direction[1] = 1;
                    continue;
                }
                cout << "lllll";
                if (direction[1] == 1) {
                    direction[1] = 0;
                    direction[2] = 1;
                    cout << "jjh";
                    continue;
                }
                if (direction[2] == 1) {
                    direction[2] = 0;
                    direction[3] = 1;
                    continue;
                }
                if (direction[3] == 1) {
                    direction[3] = 0;
                    direction[0] = 1;
                    continue;
                }
            }
        }
        sort(distance.rbegin(), distance.rend());
        return distance[0];
    }
};