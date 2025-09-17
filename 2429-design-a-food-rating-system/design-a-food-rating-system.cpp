class FoodRatings {
public:
    unordered_map<string, int> rat;
    unordered_map<string, string> t;
    unordered_map<string, set<pair<int, string>>> cr;
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            cr[cuisines[i]].insert({-ratings[i], foods[i]});
            t[foods[i]] = cuisines[i];
            rat[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating) {
        cr[t[food]].erase({-rat[food], food});
        cr[t[food]].insert({-newRating, food});
        rat[food] = newRating;
    }

    string highestRated(string cuisine) {
        return (*cr[cuisine].begin()).second;
    }
};