class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //sort the array to save decisions to include or not based on target sum 
        //i can select each element only once
        //duplicates in the set but combinations should be unique ?

         vector<vector<int>> res;
         vector<int> path;
         //9,2,2,4,6,1,5
         sort(candidates.begin(), candidates.end());
         //1,2,2,4,5,6,9 
         backtrack(candidates, target, 0, path, res);
         return res;
    }
private:
    void backtrack(const vector<int>& candidates, int remain, int start,vector<int>& path, vector<vector<int>>& res)
    {
        if(remain == 0)
        {
            res.push_back(path);
            return;
        }
        
        for(int i = start; i<candidates.size(); i++)
        {
            if(remain < candidates[i])
                break;
            if(i>start && candidates[i] == candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            backtrack(candidates, (remain-candidates[i]), i+1, path, res);
            path.pop_back();
        }
    }
};
