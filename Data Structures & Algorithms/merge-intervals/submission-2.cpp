class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // intervals - 1 -> return that .
        // sort it with all the start -> O(nlogn)
        // compare the end < start 2 -->  add to result and move to next 
        //                           --> merge it (bigger end ) --> move till you break it. ( full merged interval --> push to the result.

        // curr_interval =  1 3 - 1 5 
        // next_interval =  1 5 - 6 7 -> null
        // merge_interval = 1 3 - 
        // result -> 1 -5 
        // i - 0 

        if(intervals.size() ==1)
            return intervals;
        vector<vector<int>> res;

        //sort intervals
       // sort(intervals.begin(), intervals.end(),  [](const auto&i, const auto&j) {return (i[0] < j[0]);});
        //sort directly 
        sort(intervals.begin(), intervals.end());
        
        res.push_back(intervals[0]);

        //merge them based on the order 
        for(int i=1; i<intervals.size(); i++)
        {
            //if overlaps add it to the last one
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
