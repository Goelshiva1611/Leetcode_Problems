class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        // e odd days;
        //  o even days;
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size() / 4;
        int e = 0;
        int o = 0;
        if (n % 2 == 0) {
            e = n / 2;
        } else {
            e = (n / 2) + 1;
        }
        o = n - e;
        long long sum = 0;
        int r = pizzas.size() - 1;
        while (e) {
            sum += pizzas[r];
            e--;
            r--;
        }
        r--;
        while (o != 0) {
            sum += pizzas[r];
            o--;
            r -= 2;
        }
        return sum;
    }
};