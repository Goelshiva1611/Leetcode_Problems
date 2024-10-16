class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        string s = "";
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});
        while (!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            if (s.size() >= 2 && s[s.size() - 1] == ch &&
                s[s.size() - 2] == ch) {
                if (pq.empty())
                    break;
                int fr = pq.top().first;
                char c = pq.top().second;
                pq.pop();
                s += c;
                fr--;
                if (fr != 0)
                    pq.push({fr, c});
                pq.push({freq, ch});
            } else {
                s += ch;
                freq--;
                if (freq > 0)
                    pq.push({freq, ch});
            }
        }
        return s;
    }
};