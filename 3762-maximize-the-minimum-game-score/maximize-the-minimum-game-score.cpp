class Solution {
public:
    typedef long long ll;
    
    bool isPossible(ll target, int n, int m, vector<int>& points) {
        ll moves = 0;
        ll advanceGamesToNext = 0;
        ll normalOneMove = 0;
        
        for (int i = 0; i < n && moves <= m; i++) {
            int gamePoint = points[i];
            ll games = (target + gamePoint - 1) / gamePoint;  // Ceiling of target/gamePoint

            if (advanceGamesToNext >= games) {
                advanceGamesToNext = 0;
                normalOneMove++; // Moving to next index move
            } else {
                ll pointsCoveredByAdvanceGames = advanceGamesToNext * gamePoint;
                games = (target - pointsCoveredByAdvanceGames + gamePoint - 1) / gamePoint;  // Ceiling of (target - pointsCoveredByAdvanceGames)/gamePoint
                moves += (2 * games - 1);
                advanceGamesToNext = max(games - 1, 0LL);
                moves += normalOneMove; // Moving to this index requires moves
                normalOneMove = 0;
            }
        }
        
        return moves <= m;
    }
    
    ll maxScore(vector<int>& points, int m) {
        int n = points.size();
        if (m < n)
            return 0;
            
        ll low = 1, high = 1e15;
        ll maximumPossibleMinScore = 0;
        
        while (low <= high) {
            ll candidateScore = low + (high - low) / 2;
            if (isPossible(candidateScore, n, m, points)) {
                maximumPossibleMinScore = candidateScore;
                low = candidateScore + 1;
            } else {
                high = candidateScore - 1;
            }
        }
        return maximumPossibleMinScore;
    }
};
