class Solution {
public:
    pair<double, double> getArea(vector<vector<int>>& squares, double mid) {
        double upper = 0, lower = 0;
        for (auto& s : squares) {
            if (s[1] + s[2] <= mid)
                lower += (double)s[2] * (double)s[2];
            else if (s[1] >= mid)
                upper += (double)s[2] * (double)s[2];
            else {
                lower += (mid - (double)s[1]) * (double)s[2];
                upper += ((double)s[1] + (double)s[2] - mid) * (double)s[2];
            }
        }
        return {lower, upper};
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = 0, high = 2e9, mid = 0, ans = 0, possibleMid = 0;
        sort(squares.begin(), squares.end());
        while (low-high<-1e-5) {
            mid = low + (high - low) / 2;
            auto area = getArea(squares, mid);
            if (area.first >= area.second)
                high = mid;
            else
                low = mid;
        }
        return round(low*1e5)/1e5;
    }
};