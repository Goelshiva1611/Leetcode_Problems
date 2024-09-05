class Solution {
public:
    int count_neighbours(vector<vector<int>>& board, int row, int col) {
        int count1 = 0;
        int n = board.size();
        int m = board[0].size();
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (i == row + 1 && j == col + 1) {
                    continue;
                }
                if (i >= 0 && i < n && j >= 0 && j < m) {
                    if (board[i][j] / 2 == 1) {
                        count1++;
                    }
                }
            }
        }
        cout << count1;
        return count1;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> board1 = board;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = board[i][j] * 2 + board[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a = count_neighbours(board, i - 1, j - 1);

                if (board[i][j] / 2 == 1) {
                    if (a < 2)
                        board[i][j]--;
                    else if (a > 3)
                        board[i][j]--;

                } else {
                    if (a == 3)
                        board[i][j] += 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] %= 2;
            }
        }
    }
};