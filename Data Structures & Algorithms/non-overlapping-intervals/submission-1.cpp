class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // output - num of min remove entries to remove for non overlapping
        // we have only 1 room , how many we can cancel to accomodate non overlapping meetings
        //BF: for(0-n) for(i-n) -> increament conflicting ones for each of the slot 
        // last end > curr start ==> cant go with current slot; to be removed ++ 
        // but I can have some slots where previous end matters.
        //i just need to know least end time so that i can know if I can fit or not 
        // getminend() < currstart ==> continue ; if not, to be removed ++ ?
        // MinHeap would be good, so that now I have to first sort - onlogn & getMinHeap
        // o(n)
        
        //[[1,2],[2,4],[1,4]]
        //[[1,2],[1,4], [2,4] [3,6]]
        //res - 1
        //mh -  4 4
/*
        priority_queue <int, vector<int>, greater<int>> minHeap;
        int res = 0;
        sort(intervals.begin(),intervals.end());
        minHeap.push(intervals[0][1]);
        for(int i=1; i<intervals.size(); i++)
        {
            if(minHeap.top() > intervals[i][0])
            {
                res++;
                minHeap.pop();
                minHeap.push(intervals[i][1]);
            }
        }
        return res;*/
        int res = 0;
sort(intervals.begin(), intervals.end());

int prevEnd = intervals[0][1];

for (int i = 1; i < intervals.size(); i++) {
    // Overlap detected
    if (intervals[i][0] < prevEnd) {
        res++;
        // Greedily keep the interval that ends earliest
        prevEnd = min(prevEnd, intervals[i][1]); 
    } 
    // No overlap
    else {
        // Update prevEnd to the current interval's end time
        prevEnd = intervals[i][1];
    }
}

return res;
    }
};
