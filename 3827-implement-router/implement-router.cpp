#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

class Router {
public: 
    queue<vector<int>>qu;
    set<vector<int>>st;
    unordered_map<int,ordered_set>mp;
    int ml=0;
    Router(int memoryLimit) {
        ml=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(st.find({source,destination,timestamp})!=st.end())
            return false;
        if(qu.size()<ml)
        {
            st.insert({source,destination,timestamp});
            qu.push({source,destination,timestamp});  
            mp[destination].insert({timestamp,source});                     
        }else
        {
            vector<int>p=qu.front();
            qu.pop();
            st.erase(p);
            if(mp[p[1]].size()>0)
            {
                mp[p[1]].erase({p[2],p[0]});
                if(mp[p[1]].size()==0)                                
                    mp.erase(p[1]);
            }
            qu.push({source,destination,timestamp});   
            st.insert({source,destination,timestamp}); 
            mp[destination].insert({timestamp,source});    
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if(qu.size()==0)
            return {};
        vector<int>p=qu.front();
        qu.pop();
        st.erase(p);
        if(mp[p[1]].size()>0)
            {
                mp[p[1]].erase({p[2],p[0]});
                if(mp[p[1]].size()==0)                                
                    mp.erase(p[1]);
            }
        return p;
    }
    int getCount(int destination, int startTime, int endTime) {
        if (!mp.count(destination)) return 0;
        auto &s = mp[destination];
        return s.order_of_key({endTime+1, INT_MIN}) - 
                    s.order_of_key({startTime, INT_MIN});
    }

};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */