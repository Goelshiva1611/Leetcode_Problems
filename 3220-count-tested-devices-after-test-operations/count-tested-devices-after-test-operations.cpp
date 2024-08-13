class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        bool flag = true;
        int count = 0;
        for (int i = 0; i < n; i++) {
            flag=true;
            if (batteryPercentages[i] > 0) {
                cout<<batteryPercentages[i];
                for (int j = i + 1; j < n; j++) {
                    batteryPercentages[j]=batteryPercentages[j]-1;
                    batteryPercentages[j] = max(0, batteryPercentages[j]);
                }
                flag = false;
            }
            if (flag == false) {
                count++;
            }
        }
        return count;
    }
};