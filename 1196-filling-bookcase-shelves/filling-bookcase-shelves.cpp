class Solution {
public:

    vector<vector<int>>v;
    int dfs(vector<vector<int>>& books, int shelfWidth, int index, int remaining_width, int current_height) {
        if (index == books.size()) return current_height;
        
        // Place on a new level
        if(v[index][remaining_width]!=-1)
        {
            return v[index][remaining_width];
        }
        int place_on_new_level = current_height + dfs(books, shelfWidth, index + 1, shelfWidth - books[index][0], books[index][1]);
        
        // Place on the same level if possible
        int place_on_same_level = INT_MAX;
        if (remaining_width >= books[index][0]) {
            place_on_same_level = dfs(books, shelfWidth, index + 1, remaining_width - books[index][0], max(current_height, books[index][1]));
        }
        
        return v[index][remaining_width]=min(place_on_same_level, place_on_new_level);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        v.clear();
        v.resize(1001,vector<int>(1001,-1));
        return dfs(books, shelfWidth, 0, shelfWidth, 0);
    }
};