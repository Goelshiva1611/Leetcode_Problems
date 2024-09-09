class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int rstart = 0, cstart = 0;
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        int d = 0;
        int i = 0;
        while (head != nullptr) {
            if (d == 0) {
                for (int j = left; j <= right && head != nullptr; j++) {
                    matrix[top][j] = head->val;
                    head = head->next;
                }
                top++;
            } else if (d == 1) {
                for (int j = top; j <= bottom && head != nullptr; j++) {
                    matrix[j][right] = head->val;
                    head = head->next;
                }
                right--;
            } else if (d == 2) {
                for (int j = right; j >= left && head != nullptr; j--) {
                    matrix[bottom][j] = head->val;
                    head = head->next;
                }
                bottom--;
            } else if (d == 3) {
                for (int j = bottom; j >= top && head != nullptr; j--) {
                    matrix[j][left] = head->val;
                    head = head->next;
                }
                left++;
            }
            d = (d + 1) % 4;
        }
        return matrix;
    }
};