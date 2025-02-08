class NumberContainers {
public:
    unordered_map<int, set<int>> mp;
    unordered_map<int, int> ind;
    NumberContainers() {}

    void change(int index, int number) {
        mp[number].insert(index);
        ind[index] = number;
    }

    int find(int number) {
        if (mp.find(number) == mp.end()) {
            return -1;
        }

        for (auto it : mp[number]) {
            if (ind[it] == number) {
                return it;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */