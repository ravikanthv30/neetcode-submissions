class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        //step1: include the same number multiple times and see if target can be reached ? if(target > pathSum) return 
            // if(target == pathSum) add this combo to result
        //step2: if returned then go back one pop element and add next element and do the same till this element addition exceeds target
        // repeat this till all elements selected 

        vector<vector<int>> res;
        vector<int> path;
        int pathsum = 0;
        int start =0;
        backtrack(nums, target, start, pathsum, path, res);
        return res;
    }
    private:
    void backtrack(const vector<int>& nums, const int target, int start, int &pathsum, vector<int>& path, vector<vector<int>>& res)
    {
        if(pathsum >target )
            return;
        if(pathsum == target)
        {
            res.push_back(path);
            return;
        }

        for(int i=start; i<nums.size(); i++)
        {
            pathsum+=nums[i];
            path.push_back(nums[i]);
            backtrack(nums, target, i, pathsum, path, res);
            int del = path.back();
            pathsum-=del;
            path.pop_back();
        }
        return;
    }
};
