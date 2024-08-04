class Solution {
public:
unordered_map<string,bool>mp;
    bool isScramble(string a, string b) {
        if(a.compare(b)==0)
        return true;
        
        string key=a+b;
        if(mp.find(key)!=mp.end())
        return mp[key];
        bool flag=false;
        int n=a.length();
        for(int i=1;i<n;i++)
        {
            if((isScramble(a.substr(0,i),b.substr(n-i,i))==true && isScramble(a.substr(i,n-i),b.substr(0,n-i))==true) 
            || (isScramble(a.substr(0,i),b.substr(0,i))==true && isScramble(a.substr(i,n),b.substr(i,n))==true))
            {
                flag=true;
                break;
            }
        }
        return mp[key]=flag;
    }
};