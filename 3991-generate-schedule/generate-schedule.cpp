class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {

        if (n <= 4) {
            return {};
        }
        int tm = n * (n - 1);
        vector<vector<int>> schedule;
        vector<int> teams;
        vector<int> gamesPlayed(n, 0);
        for (int i = 0; i < n; i++) {
            teams.push_back(i);
        }
        vector<vector<bool>> matches;
        matches.resize(n, vector<bool>(n, false));
        int lt1 = -1;
        int lt2 = -1;
        for (int day = 0; day < tm; day++) {
            unordered_set<int> available;
            for (int team : teams) {
                if (team != lt1 && team != lt2) {
                    available.insert(team);
                }
            }
            int miniScore = INT_MAX;
            int Firstteam = -1;
            int Secondteam = -1;

            for (int team1 : available) {
                for (int team2 : available) {
                    if (team1 == team2)
                        continue;
                    if (matches[team1][team2])
                        continue;
                    int score = gamesPlayed[team1] + gamesPlayed[team2];
                    if (score < miniScore) {
                        miniScore = score;
                        Firstteam = team1;
                        Secondteam = team2;
                    }
                }
            }
            if (Firstteam == -1 || Secondteam == -1)
                return {};
            schedule.push_back({Firstteam, Secondteam});
            matches[Firstteam][Secondteam] = true;
            lt1 = Firstteam;
            lt2 = Secondteam;
            gamesPlayed[Firstteam]++;
            gamesPlayed[Secondteam]++;
        }
        return schedule;
    }
};