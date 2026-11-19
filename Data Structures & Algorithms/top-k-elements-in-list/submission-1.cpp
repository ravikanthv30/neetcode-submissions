class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // BFmethod - run 2 loops see each element how many times it is repated and store
        // 1st loop sort all elements, 2 loop count each new element
        // traverse and use map and do count  --> O(n), space - O(n)
        //edge conditions
        unordered_map<int, int> m;
        vector<int> res = {};
        multimap<int, int> f;
        if(k>nums.size() && k <=0)
        {
            return res;
        }
        for(auto i : nums)
        {
            m[i]++;
        }
        for(auto i: m)
        {
            //sort the map with number of occurance
            f.insert({i.second,i.first});
        }
        int n = 1;
        for (auto it = f.rbegin(); it != f.rend() && n<=k; ++it)
        {
            n++;
            res.push_back(it->second);
        }
        return res;
    }
};
