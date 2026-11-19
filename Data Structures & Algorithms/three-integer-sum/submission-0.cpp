class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
    //BF: 3 for loops, i, j, k, nums[] add is good add it to res and return
  
    set<vector<int>> res;
   /*for(int i =0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            for(int k =j+1; k<nums.size(); k++)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    res.insert({nums[i],nums[j],nums[k]});
                }
            }
        }
    }
    return vector<vector<int>>(res.begin(), res.end());
     */
  //pointers- l, m, r --> move the window trying all
  //sort the array and then do it
  // fix i and then find 2 sum 
    map <int, int> m;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++)
    {
        //find 2 sum for -i 
        int target = 0 - nums[i];
        m.clear();
        for(int j=i+1; j < nums.size(); j++)
        {
            auto it = m.find(target-nums[j]);
            if(it != m.end())
            {
                res.insert({nums[i], nums[j], it->first});                
            }
            m[nums[j]] = j;
        }
    }
    return  vector<vector<int>>(res.begin(), res.end());
    }
};
