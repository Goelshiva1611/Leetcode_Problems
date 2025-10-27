class Bank {
public:
    unordered_map<long long, long long> mp;
    Bank(vector<long long>& balance) {
        for (int i = 0; i < balance.size(); i++) {
            mp[i + 1] = balance[i];
        }
    }

    bool transfer(int account1, int account2, long long money) {
        if (mp.find(account1) == mp.end() || mp.find(account2) == mp.end()) {
            return false;
        }
        if (mp[account1] >= money) {
            mp[account1] -= money;
            mp[account2] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (mp.find(account) == mp.end())
            return false;
        mp[account] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (mp.find(account) == mp.end())
            return false;
        if (mp[account] < money)
            return false;
        mp[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */