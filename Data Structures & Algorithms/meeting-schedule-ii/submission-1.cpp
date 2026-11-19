/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
    //problem can be of finding number of unique slots 
    // group them into different buckets when its conflicting with no start and end conflicts
    //if no conflicts --> 1 meeting room is good
    
    //BF: sort the list of start times 
    //if end_i > start_j -> move to [conflict list]
    // if I do the same and form into new list ; repeat till conflict list is 0 
    //return num_lists ;  O(n2); O(n)

    // [0 - 40] [5 - 10] [15 - 20] //2 [40 - 50] [25 - 30]
    // [0 - 40] [5 - 10] [15 - 50] [45 - 60] [40 - 50]
    // start_i < end_i <= start_j < end_j --> can be in one room 
    //
    // end1 40, end2 - 50  --> maintain ends in a vector + binary search ?
    // start_k  > any of the end -> no increament ; update max of that room 
    // if not -> room++
    // O(nlogn); o(n)

    int n = intervals.size();
    if(n==0)
    {
        return 0;
    }
    if(n==1)
        return 1;

    sort(intervals.begin(), intervals.end(), [](const auto&i, const auto&j){return (i.start < j.start);});
    int room = 1;
    // Min-heap to track the end times of ongoing meetings
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // Add the first meeting's end time
    minHeap.push(intervals[0].end);
    for(int i=1; i < intervals.size(); i++)
    {
 /*       if(intervals[i-1].end <= intervals[i].start &&
           intervals[i-1].end <= intervals[i].end)
        {
            continue;
        }
        else
        {
            bool accom = false;
            for(auto e: ends)
            {
                if(e <= intervals[i].start)
                {
                    accom=true;
                    break;
                }
            }
            if(accom)
                continue;
            int new_end = max(intervals[i-1].end, intervals[i].end);
            ends.push_back(new_end);
            room++;
        }*/
        // If the earliest ending meeting finishes before or when the current meeting starts
        // the room is free. Pop the old end time.
        if (intervals[i].start >= minHeap.top()) {
            minHeap.pop();
        }
        
        // Push the current meeting's end time. 
        // This either updates the reused room, or allocates a new one.
        minHeap.push(intervals[i].end);
    }
    return minHeap.size();;
    }
};
