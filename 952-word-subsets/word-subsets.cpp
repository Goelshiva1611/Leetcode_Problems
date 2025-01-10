class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words2.size();
        vector<string> v;
       
        map<char, int> mp2;
        
        for (int i = 0; i < n; i++) {
            string first = words2[i];
            map<char, int> mp3;
            for (int j = 0; j < first.size(); j++) {
                mp3[first[j]]++;
            }
            for(auto  it :mp3)
            {
                mp2[it.first]=max(mp3[it.first],mp2[it.first]);
            }
        }
        for (int i = 0; i < words1.size(); i++) {
            string first = words1[i];
            unordered_map<char, int> mp1;
            for (int j = 0; j < first.size(); j++) {
                mp1[first[j]]++;
            }
            bool flag = true;
            for (auto it : mp2) {
                char r = it.first;
                cout << r;
                cout << mp1[r];
                cout << endl;
                if (mp2[r] > mp1[r]) {
                    cout << "kkk";
                    flag = false;
                    break;
                }
            }
            cout << "hello";
            if (flag == true) {
                cout << "jjjjj";
                v.push_back(first);
            }
        }
        return v;
    }
};