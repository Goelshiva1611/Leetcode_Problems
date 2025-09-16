class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> answer;
        for (auto num : nums) {
            while (!answer.empty()) {
                int a = answer[answer.size() - 1];
                int b = num;
                int x = gcd(a, b);
                if (x <= 1) {
                    break;
                }
                answer.pop_back();
                int l=lcm(a,b);
                num=l;
            }
            answer.push_back(num);
            
        }
        return answer;
    }
};

/*
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        vector<int> answerprev;
        while (true) {
            deque<int> dq;
            vector<int> answer;
            for (auto it : nums)
                dq.push_back(it);
            while (dq.size() >= 2) {
                int a = dq.front();
                dq.pop_front();
                int b = dq.front();
                dq.pop_front();
                int x = gcd(a, b);
                if (x > 1) {
                    dq.push_front(lcm(a, b));
                } else {
                    answer.push_back(a);
                    dq.push_front(b);
                }
            }
            while (!dq.empty()) {
                int a = dq.front();
                answer.push_back(a);
                dq.pop_front();
            }
            if (answer == answerprev) {

                break;
            }
            answerprev = answer;
            nums=answerprev;
        }
        return answerprev;
    }
};*/