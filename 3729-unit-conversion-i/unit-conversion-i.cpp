class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();
        vector<int> answer;
        int modulo = 1000000007;
        vector<int> units(n + 1, 1);
        answer.push_back(1);
        for (int i = 0; i < n; i++) {
            int a = conversions[i][0] % modulo;
            int b = conversions[i][1] % modulo;
            int c = conversions[i][2] % modulo;
            long long p=1;
            long long  t = ( p*c * units[a]) % modulo;
            //1e9 is double * double throws a error so you have a need to typecast this one 
            units[b] = t;
        }
        return units;
    }
};