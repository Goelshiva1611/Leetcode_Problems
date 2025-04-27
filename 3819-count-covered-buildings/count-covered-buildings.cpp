class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>> rows(n + 1, vector<int>(2, 0));
        vector<vector<int>> columns(n + 1, vector<int>(2, 0));
        for (int i = 0; i < buildings.size(); i++) {
            int a = buildings[i][0];
            int b = buildings[i][1];
            columns[b][0] = (columns[b][0] == 0) ? a : min(columns[b][0], a);
            columns[b][1] = (columns[b][1] == 0) ? a : max(columns[b][1], a);
            rows[a][0] = (rows[a][0] == 0) ? b : min(rows[a][0], b);
            rows[a][1] = (rows[a][1] == 0) ? b : max(rows[a][1], b);
        }
        int answer = 0;
        for (int i = 0; i < buildings.size(); i++) {
            int a = buildings[i][0];
            int b = buildings[i][1];
            if ((rows[a][0] < b && rows[a][1] > b) &&
                (columns[b][0] < a && columns[b][1] > a))
                answer++;
        }
        return answer;
    }
};