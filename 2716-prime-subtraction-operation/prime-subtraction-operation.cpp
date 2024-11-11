class Solution {
public:
    bool isprime(int num) {
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    set<int> findallprime() {
        set<int> st;
        for (int i = 2; i < 1000; i++) {
            if (isprime(i)) {
                st.insert(i);
            }
        }
        st.insert(2);
        return st;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        set<int> st = findallprime();
        for (int i = n-1; i>=1; i--) {
            if (nums[i-1] - nums[i] >= 0) {
                for (int k = 2; k <nums[i-1]; k++) {
                    if (st.find(k) != st.end()) {
                        int p=nums[i-1]-k;
                        if(p-nums[i]<0)
                        {
                            nums[i-1]=nums[i-1]-k;
                            break;
                        }
                    }
                }
                if(nums[i-1]-nums[i]>=0)
                {
                    return false;
                }

            }
            
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= 0) {
                cout<<"hello";
                return false;
            }
        }
        return true;
    }
};