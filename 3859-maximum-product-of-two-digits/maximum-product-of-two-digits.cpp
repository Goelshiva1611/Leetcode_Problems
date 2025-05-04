class Solution {
public:
    int maxProduct(int n) {
        string p=to_string(n);
        sort(p.begin(),p.end());
        return (p[p.size()-1]-'0')*(p[p.size()-2]-'0');
    }
};