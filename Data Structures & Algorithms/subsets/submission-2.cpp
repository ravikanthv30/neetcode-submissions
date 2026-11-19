class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, 0, path, res);
        return res;
    }
//i can have possiblities based on the size of the window starting from 0->n-1 => each i! possiblities => n*n!/n = n! --> WRONG -> each one have 2 possibltied -> 2^n
//for each size will go deep and get lists.
//or I can take one elemenet and create all possiblities as i need to avoid the duplicates 
// for i in 0-n => 0-n based sets 
// 1, 12, 13, 123 ;  2, 23 ; 3  ==> GOOD thinking.. but NO implementation at all :(

// res {},  {1}
// path
// {} - 0
    //==> 2 {3}
// {1} - 0
    //=> 1 {2}
    //==> 2 {2,3}
// {1,2} - 1 
    // ==> {1,3} 
// {1,2,3} - 2

private:
    void backtrack(const vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        // 1. Every state in the tree is a valid subset, so add it immediately
        res.push_back(path);

        // 2. Loop through remaining elements starting from 'start'
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);           // Choose nums[i]
            backtrack(nums, i + 1, path, res); // Explore remaining elements after index 'i'
            path.pop_back();                   // Backtrack (undo choice)
        }
    }
};