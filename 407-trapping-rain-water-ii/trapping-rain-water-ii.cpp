class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<PP>> boundaryCells;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int r = 0; r < m; ++r) {
            for (int c : {0, n - 1}) { //0 : left most boundary, cols-1 right most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        for (int c = 0; c < n; ++c) {
            for (int r : {0, m - 1}) { //0 : top most boundary, rows-1 bottom most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        int trappedWater = 0;

        while (!boundaryCells.empty()) {
            auto [height, cell] = boundaryCells.top();
            boundaryCells.pop();

            int i = cell.first;
            int j = cell.second;

            for (vector<int>& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];


                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                    
                    trappedWater += max(0, height - heightMap[i_][j_]);
                    
                    boundaryCells.push({max(height, heightMap[i_][j_]), {i_, j_}});

                    
                    visited[i_][j_] = true;
                }
            }
        }

        return trappedWater;
    }
};



/*
Brute force will not work here
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<int>> left(n, vector<int>(m, 0));
        vector<vector<int>> right(n, vector<int>(m, 0));
        vector<vector<int>> up(n, vector<int>(m, 0));
        vector<vector<int>> down(n, vector<int>(m, 0));
        cout << "hello";
        for (int i = 0; i < n; i++) {
            int l = 0;
            for (int j = 0; j < m; j++) {
                left[i][j] = l;
                l = max(l, heightMap[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            int l = 0;
            for (int j = m - 1; j >= 0; j--) {
                right[i][j] = l;
                l = max(l, heightMap[i][j]);
            }
        }
        cout << "hi";
        for (int i = 0; i < m; i++) {
            int l = 0;
            for (int j = 0; j < n; j++) {
                up[j][i] = l;
                l = max(l, heightMap[j][i]);
            }
        }
        cout << "kkk";
        for (int i = 0; i < m; i++) {
            int l = 0;
            for (int j = n - 1; j >= 0; j--) {
                down[j][i] = l;
                l = max(l, heightMap[j][i]);
            }
        }
        cout << "hello";
        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                
                int p = min({left[i][j], right[i][j], down[i][j], up[i][j]});
                cout<<p;
                int diff = p - heightMap[i][j];
                if (diff >= 0)
                {
                    water += diff;
                    cout<<water;
                    cout<<diff;
                    cout<<endl;
                }
            }
        }
        return water;
    }
};

*/