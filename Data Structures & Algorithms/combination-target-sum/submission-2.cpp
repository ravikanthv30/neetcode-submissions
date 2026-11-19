class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // 1. Sort to enable early loop break (pruning)
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, target, 0, path, res);
        return res;
    }

private:
    void backtrack(const vector<int>& nums, int remain, int start, vector<int>& path, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // 2. PRUNING: Because nums is sorted, if nums[i] exceeds remain,
            // all elements after 'i' will also exceed remain. Stop immediately!
            if (nums[i] > remain) break;

            path.push_back(nums[i]);
            backtrack(nums, remain - nums[i], i, path, res); // Pass 'remain - nums[i]' by value
            path.pop_back();
        }
    }
};