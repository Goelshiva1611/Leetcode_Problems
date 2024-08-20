class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int l = 0;
        int r = piles.size() - 1;
        int t = 1;
        int alice = 0;
        int bob = 0;
        while (l < r) {
            if (t == 1) {
                if (piles[l] <= piles[r] && t == 1) {
                    alice += piles[r];
                    r--;
                } else {
                    alice += piles[l];
                    l++;
                }
            }
            cout << alice;

            if (t == 0) {
                if (piles[l] <= piles[r] && t == 0) {
                    bob += piles[l];
                    r--;
                } else {
                    alice += piles[r];
                    l++;
                }
            }
            t = (t == 1) ? 0 : 1;
        }
        if (alice > bob) {
            return true;
        }
        return false;
    }
};