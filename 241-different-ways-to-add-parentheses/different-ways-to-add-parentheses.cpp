class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '-' || expression[i] == '+' ||
                expression[i] == '*') {
                vector<int> l_side = diffWaysToCompute(expression.substr(0, i));
                vector<int> r_side = diffWaysToCompute(
                    expression.substr(i + 1, expression.size() - i - 1));
                for (int l = 0; l < l_side.size(); l++) {
                    int x = l_side[l];
                    for (int r = 0; r < r_side.size(); r++) {
                        int y = r_side[r];
                        if (expression[i] == '-') {
                            results.push_back(x - y);
                        } else if (expression[i] == '+') {
                            results.push_back(x + y);
                        } else if (expression[i] == '*') {
                            results.push_back(x * y);
                        }
                    }
                }
            }
        }
        if (results.size() == 0) {
            results.push_back(stoi(expression));
        }
        return results;
    }
};