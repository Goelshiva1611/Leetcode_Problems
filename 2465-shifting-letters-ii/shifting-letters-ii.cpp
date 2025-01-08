class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<char> forward;
        forward = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                   'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                   's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
       

        int n = shifts.size();
        vector<int> t;
        t.resize(s.size(),0);
        for (int i = 0; i < n; i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];
            if (direction == 1) {
                t[start] += 1;
                if (end < s.size() - 1) {
                    t[end+1] -= 1;
                }
            }
            if (direction == 0) {
                t[start] -= 1;
                if (end < s.size() - 1) {
                    t[end+1] += 1;
                }
            }
        }
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            sum+=t[i];
            cout<<sum;
            sum=sum%26;
            int z=s[i]-'a';
            cout<<" ";

            cout<<z<<endl;
            if(sum+z>=0)
            s[i]=forward[(sum+z)%26];
            else
            {
                s[i]=forward[26-abs((z+sum)%26)];
            }
        }
        //  int n = shifts.size();
        // for (int i = 0; i < n; i++) {
        //     string t=s;
        //     int a = shifts[i][0];
        //     int b = shifts[i][1];
        //     int c = shifts[i][2];
        //     if (c == 0) {
        //         // shift backward;
        //         for (int j = a; j <= b; j++) {
        //             int p = s[j] - 'a';
        //             t[j]= backward[p];
        //         }
        //     } else {
        //         // shift forward;
        //         for (int j = a; j <= b; j++) {
        //             int p = s[j] - 'a';
        //             t[j]= forward[p];
        //         }

        //     }
        //     s = t;
        // }
        return s;
    }
};