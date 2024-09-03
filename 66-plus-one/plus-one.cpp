class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        vector<int> ans;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
                carry = 1;
                continue;
            }
            digits[i] += 1;
            carry = 0;
            break;
        }
        if (carry == 1) {
            reverse(digits.begin(), digits.end());
            digits.push_back(1);
            reverse(digits.begin(), digits.end());
            return digits;
        }
        return digits;
    }
};