class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>> rows(n + 1, vector<int>(2, 0));
        vector<vector<int>> columns(n + 1, vector<int>(2, 0));
        for (int i = 0; i < buildings.size(); i++) {
            int a = buildings[i][0];
            int b = buildings[i][1];
            if (columns[b][0] == 0) {
                cout << a;
                columns[b][0] = a;
            } else {
                columns[b][0] = min(columns[b][0], a);
            }

            if (columns[b][1] == 0) {
                columns[b][1] = a;
            } else {
                columns[b][1] = max(columns[b][1], a);
            }

            if (rows[a][0] == 0) {
                rows[a][0] = b;
            } else {
                rows[a][0] = min(rows[a][0], b);
            }

            if (rows[a][1] == 0) {
                rows[a][1] = b;
            } else {
                rows[a][1] = max(rows[a][1], b);
            }
        }
        int answer = 0;
        for (int i = 0; i < buildings.size(); i++) {
            int a = buildings[i][0];
            int b = buildings[i][1];
            if ((rows[a][0] < b && rows[a][1] > b) &&
                (columns[b][0] < a && columns[b][1] > a)) {
                answer++;
            }
        }
        return answer;
    }
};