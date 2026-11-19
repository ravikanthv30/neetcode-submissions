class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //input is nums and combinations is output
        vector<vector<int>> res;
        // perumations -> n! possiblities
        // fix first element and then permutate others like wise for all the indexes 
        vector<int> path;
        vector<int> used(nums.size(), false);
        backtrack(nums, used, path, res);
        return res;
    }

//1 2 3 
// path - 1 3
// res = 123 

private:
    void backtrack(const vector<int>& nums, vector<int> & used, vector<int>& path, vector<vector<int>>& res)
    {
        if(path.size() >= nums.size()) 
        {
            res.push_back(path);
            return;
        }

        for(int i = 0; i< nums.size(); i++)
        {
            if(used[i])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used, path, res);
            path.pop_back();
            used[i] = false;
        }
    }
};
