class TimeMap {
public:
    //hashmap -> no duplicate 
    // key1 ->  <tm>
    // key2 ->  <tm> <tm>
    unordered_map <string , vector <pair<int, string>>> um;

    TimeMap() {
        um.clear();
    }
    
    // A [h,1] [s,3]
    // 
    void set(string key, string value, int timestamp) {
        //same k,v with different timestamp
        //o(1)
     /*   if(um.count(key) > 0)
        {
            vector <pair<int, string>>& tmp = um[key];
            tmp.push_back({timestamp, value});
        }
        else
        {
            vector <pair<int, string>> list;
            list.push_back({timestamp,value});
            um.insert({key, list});
        }
       */
       um[key].emplace_back(timestamp, value);

    }
    
    string get(string key, int timestamp) {
        //same key multiple values -> give back last prev one.
        //o(logn)
        string res ="";
        auto it = um.find(key);
        if( it != um.end())
        {
            const auto &tmp = it->second;
            int l=0, r=tmp.size()-1;
 
            while(l<=r)
            {
                int m = l+(r-l)/2;

                if(tmp[m].first <= timestamp)
                {
                    res = tmp[m].second;
                    l=m+1;
                }
                else 
                    r=m-1;
            }

        }
        
        return res;

    }
};
