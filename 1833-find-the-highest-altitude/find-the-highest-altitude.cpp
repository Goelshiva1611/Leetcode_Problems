class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitude;
        altitude.push_back(0);
        int n=gain.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+gain[i];
            altitude.push_back(sum);
        }
        sort(altitude.rbegin(),altitude.rend());
        return altitude[0];
    }
};