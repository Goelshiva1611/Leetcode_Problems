class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.rbegin(), tasks.rend());
        int j = 0;
        int r = 0;
        int q = 0;
        int result = 0;
        int t = 0;
        int i = 0;
        while (i < processorTime.size()) {
            q = 0;
            while (q != 4 && t < tasks.size()) {
                r = max(r, tasks[t] + processorTime[i]);
                cout<<r;
                cout<<endl;
                t++;
                q++;
            }
            i++;
            result = max(result, r);
        }
        return result;
    }
};