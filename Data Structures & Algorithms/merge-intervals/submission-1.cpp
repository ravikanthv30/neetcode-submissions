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
        sort(intervals.begin(), intervals.end(),  [](const auto&i, const auto&j) {return (i[0] < j[0]);});

        
        //merge them based on the order 
        for(int i=0; i<intervals.size(); i++)
        {
            vector<int> merge_interval;
            merge_interval.push_back(intervals[i][0]);
            merge_interval.push_back(intervals[i][1]);

            while((i<intervals.size()-1) && ( merge_interval[1] >= intervals[i+1][0]))
            {
                //cout<<"merge"<<merge_interval[1]<<"end"<<intervals[i+1][1]<<endl;
                merge_interval[1] = max(merge_interval[1],intervals[i+1][1]);
                i++;
            }
           // cout<<"break start"<<intervals[i][0]<<"end"<<intervals[i][1]<<"i"<<i<<endl;
            res.push_back(merge_interval);
        }

        return res;
    }
};
