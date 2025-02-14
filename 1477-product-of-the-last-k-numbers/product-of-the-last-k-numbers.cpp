class ProductOfNumbers {
public:
    typedef long long int ll;
    vector<ll> v;
    vector<ll> ans;
    ll sum = 1;
    ll x = -1;
    ProductOfNumbers() {}
    void add(int num) {
        if (num == 0) {
            x = ans.size();
        }
        sum *= num;
        if (sum == 0) {
            sum = 1;
            ans.push_back(1);
        } else
            ans.push_back(sum);
    }

    int getProduct(int k) {
        ll n = ans.size();
        if (n - k <= x)
            return 0;
        if (k != ans.size()) {
            ll a = sum;
            ll b = ans[ans.size() - k - 1];
            return a / b;
        }
        return sum;
    }
};


/*
class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {}
    void add(int num) { v.push_back(num); }
    int getProduct(int k) {
        int sum = 1;
        int n = v.size();
        for (int i = n - 1; i >= n - k; i--) {
            sum *= v[i];
        }
        return sum;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */