class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (head != nullptr) {
            for (int j = left; j <= right && head != nullptr; j++) {
                matrix[top][j] = head->val;
                head = head->next;
            }
            top++;
            for (int j = top; j <= bottom && head != nullptr; j++) {
                matrix[j][right] = head->val;
                head = head->next;
            }
            right--;
            for (int j = right; j >= left && head != nullptr; j--) {
                matrix[bottom][j] = head->val;
                head = head->next;
            }
            bottom--;
            for (int j = bottom; j >= top && head != nullptr; j--) {
                matrix[j][left] = head->val;
                head = head->next;
            }
            left++;
        }
        return matrix;
    }
};