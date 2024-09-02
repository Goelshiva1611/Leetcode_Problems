class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        double X = coordinates[0][0] - coordinates[1][0];
        double Y = coordinates[0][1] - coordinates[1][1];
        double m = 0;;
        if (X != 0 && Y != 0) {
            m = Y / X;
            for (int i = 1; i < n-1; i++) {
                double X1 = coordinates[i][0] - coordinates[i + 1][0];
                double Y1 = coordinates[i][1] - coordinates[i + 1][1];
                if (X1 == 0)
                    return false;
                if (Y1 == 0)
                    return false;
                double p = Y1 / X1;
                if (p != m) {
                    return false;
                }
            }
        }
        if (X == 0) {
            for (int i = 1; i < n-1; i++) {
                int X1 = coordinates[i][0] - coordinates[i + 1][0];
                int Y1 = coordinates[i][1] - coordinates[i + 1][1];
                if (X1 != 0)
                    return false;
            }
        }
        if (Y == 0) {
            for (int i = 1; i < n-1; i++) {
                int X1 = coordinates[i][0] - coordinates[i + 1][0];
                int Y1 = coordinates[i][1] - coordinates[i + 1][1];
                if (Y1 != 0)
                    return false;
            }
        }

        return true;
    }
};