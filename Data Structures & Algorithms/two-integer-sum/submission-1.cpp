class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> res(0,0);
  /*      for(int i =0; i < nums.size(); i++)
        {
            for(int j =i; j < nums.size(); j++)
            {
                if (nums[i]+nums[j]== target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }*/
    
    unordered_map <int, int> m;
    for(int i=0; i < nums.size(); i++)
    {
        auto it = m.find(target-nums[i]);
        if(it != m.end())
        {
            res.push_back(it->second);
            res.push_back(i);
            break;
        }
        m[nums[i]] = i;
    }
    return res;
    }
};
