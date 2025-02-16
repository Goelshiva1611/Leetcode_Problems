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
    double low = 0, high = INT_MAX, mid = 0, ans = 0, possibleMid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        auto area = getArea(squares, mid);
        if (ans == mid)
            break;
        if (area.first > area.second)
            high = mid;
        else
            low = mid;
        ans = mid;
    }

    // check further, if the mid is not overlapping with any square then return
    // answer as the larget value of upper y value of square which is smaller
    // then mid.
    for (auto s : squares) {
        if (ans >= (double)(s[1] + s[2]))
            possibleMid = max(possibleMid, (double)(s[1] + s[2]));
        if (ans > (double)s[1] && ans < (double)(s[1] + s[2]))
            possibleMid = INT_MAX;
    }
    return min(possibleMid, ans);
}
};