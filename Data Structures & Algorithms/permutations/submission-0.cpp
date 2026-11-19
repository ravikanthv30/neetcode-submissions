class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //input is nums and combinations is output
        vector<vector<int>> res;
        // perumations -> 2^n possiblities ?
        // fix first element and then permutate others like wise for all the indexes 
        vector<int> path;
        backtrack(nums, 0, path, res);
        return res;
    }

//1 2 3 
// path - 1 3
// res = 123 

private:
    void backtrack(const vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res)
    {
        if(path.size() >= nums.size()) // i=3 [1 3]
        {
            res.push_back(path);
            return;
        }

        for(int i = 0; i< nums.size(); i++)
        {
            auto it = find(path.begin(), path.end(), nums[i]);
            if(it != path.end())
                continue;
            path.push_back(nums[i]);
            backtrack(nums, i+1, path, res);
            path.pop_back();
        }
    }
};
