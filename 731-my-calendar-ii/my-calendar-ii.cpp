class MyCalendarTwo {
public:
    vector<pair<int, int>> doublebooking;
    vector<pair<int, int>> booking;
    MyCalendarTwo() {}
    bool book(int start, int end) {
        for (int i = 0; i < doublebooking.size(); i++) {
            int s = doublebooking[i].first;
            int e = doublebooking[i].second;
            if (max(s, start) < min(e, end))
                return false;
        }
        for (int i = 0; i < booking.size(); i++) {
            int s = booking[i].first;
            int e = booking[i].second;
            if (max(s, start) < min(e, end))
                doublebooking.push_back({max(s, start), min(e, end)});
        }
        booking.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */