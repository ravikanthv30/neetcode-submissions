class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        //so intervals is sorted ? if so, we can add this new one first and try to go through the list and merge them ?
        // O(nlogn) and O(1)
        //Sort , add new and then merge , return 
        //[1 3] [2 5] [4 6] 

        if(intervals.empty())
            return {newInterval};
        //sort 
       // sort(intervals.begin(), intervals.end());

        //add 
        int i=0;
        for(; i<intervals.size(); i++)
        {
            if(intervals[i][0] <  newInterval[0])
                continue;
            else
            {
                intervals.insert((intervals.begin() + i), newInterval);
                break;
            }
        }
        if(i==intervals.size())
        {
            intervals.push_back(newInterval);
        }

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++)
        {
            //if last_end > start - merge 
            if(res.back()[1] >= intervals[i][0])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
                res.push_back(intervals[i]);
        }

        return res;
    }
};
