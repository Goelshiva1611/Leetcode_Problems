class Solution {
public:
    bool ismagic(int row, int col, vector<vector<int>>& grid) {
        // Check if all numbers are distinct and between 1 to 9
        set<int> uniqueNumbers;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if(uniqueNumbers.find(grid[i][j])!=uniqueNumbers.end())
                {
                    return false;
                }
                if (grid[i][j] < 1 || grid[i][j] > 9 ) {
                    return false;
                }
                uniqueNumbers.insert(grid[i][j]);

            }
        }

        // Check rows, columns, and diagonals
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];

        // Check all rows
        for (int i = row; i < row + 3; i++) {
            int rowSum = 0;
            for (int j = col; j < col + 3; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum != sum)
                return false;
        }

        // Check all columns
        for (int j = col; j < col + 3; j++) {
            int colSum = 0;
            for (int i = row; i < row + 3; i++) {
                colSum += grid[i][j];
            }
            if (colSum != sum)
                return false;
        }

        // Check diagonals
        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] !=
            sum)
            return false;
        if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] !=
            sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        if (n < 3 || m < 3) {
            return 0;
        }
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (ismagic(i, j, grid)) {
                    ans = ans + 1;
                }
            }
        }
        return ans;
    }
};