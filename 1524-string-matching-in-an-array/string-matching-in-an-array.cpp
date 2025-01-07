class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> st;
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            for (int j = 0; j < w.length(); j++) {
                string p = "";
                p += w[j];
                st.insert(p);
                for (int k = j + 1; k < w.length(); k++) {
                    p += w[k];
                    if(p!=w)
                    st.insert(p);
                }
            }
            
        }
        vector<string>v;
        for(int i=0;i< words.size();i++)
        {
            if(st.find(words[i])!=st.end())
            {
                v.push_back(words[i]);
            }
        }
        return v;
    }
};