class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> a;
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int rstart = 0, cstart = 0;
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        int d = 0;
        int i = 0;
        while (i < a.size()) {
            if (d == 0) {
                for (int j = left; j <= right && i < a.size(); j++) {
                    matrix[top][j] = a[i];
                    i++;
                }
                top++;
            } else if (d == 1) {
                for (int j = top; j <= bottom && i < a.size(); j++) {
                    matrix[j][right] = a[i];
                    i++;
                }
                right--;
            } else if (d == 2) {
                for (int j = right; j >= left && i < a.size(); j--) {
                    matrix[bottom][j] = a[i];
                    i++;
                }
                bottom--;
            } else if (d == 3) {
                for (int j = bottom; j >= top && i < a.size(); j--) {
                    matrix[j][left] = a[i];
                    i++;
                }
                left++;
            }

            d = (d + 1) % 4;
        }
        return matrix;
    }
};