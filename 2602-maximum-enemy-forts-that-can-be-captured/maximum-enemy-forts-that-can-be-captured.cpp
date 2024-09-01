class Solution {
public:
    int captureForts(vector<int>& forts) {
        vector<int> v;
        int n = forts.size();
        for (int i = 0; i < n; i++) {
            if (forts[i] == 1) {
                // start attacking kyuli mera fort hai
                int count = 0;
                bool flag = false;
                for (int j = i + 1; j < n; j++) {
                    if (forts[j] == -1 ) {
                        flag = true;
                        break;
                    }
                    if(forts[j]==1)
                    {
                        break;
                    }
                    if (forts[j] == 0) {
                        count++;
                    }
                }
                if (flag == true) {
                    v.push_back(count);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (forts[i] == 1) {
                // start attacking kyuli mera fort hai
                cout<<i;
                int count = 0;
                bool flag = false;
                for (int j = i - 1; j >= 0; j--) {
                    if (forts[j] == -1) {
                        flag = true;
                        cout<<"tt";
                        cout<<endl;
                        break;
                    }
                    if(forts[j]==1)
                    {
                        cout<<j;
                        cout<<"jjd";
                        cout<<endl;
                        break;
                    }
                    if (forts[j] == 0) {
                        count++;
                    }
                }
                if (flag == true) {
                    v.push_back(count);
                }
            }
        }
        if (v.size() > 0) {
            sort(v.rbegin(), v.rend());
            return v[0];
        }
        return 0;
    }
};