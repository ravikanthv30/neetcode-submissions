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
    bool canAttendMeetings(vector<Interval>& intervals) {
    //sort all the intervals start times
    //if start[i] < end[i] < start[j] < end[j]
    if(intervals.size() <= 1)
    {
        return true;
    }

    sort(intervals.begin(), intervals.end(), [](const auto i, const auto j){ return  (i.start < j.start);});

    for(int i=1; i < intervals.size();i++)
    {
     //check if previous interval or start is cross the current one return false;
        auto curr = intervals[i];
        auto prev = intervals[i-1];

        if(!( (prev.start <= prev.end) && 
              (prev.end  <= curr.start) &&
              (curr.start <= curr.end)
            )
          )
        {
            return false;
        }
    }
    return true;
 }
};

//input vector<pair<int, int>>
//output true, false
//5 - 10 //15-20//0 -30
//0---5---10---15--20----30 
/*
for(int i=0; i<meeting.size(); i++)
{
  auto mt=meeting[i];
  for(int j=0; j< i-1 ; j++)
  {
     prevmt=meeting[j];
     if(mt[0] < prevmt[0] || 
        prevmt[1] < mt[1])
	{
		return false;
	}
  }
  return true;
}
*/
//==========
/*
int min =INT_MAX;
int max=INT_MIN;
for(int i=0; i<meeting.size(); i++)
{
   auto mt=meeting[i];
   min = min(min, mt[0]);
   max = max(max, mt[1]);
   prevmt=meeting[j];
   if(mt[0] < prevmt[0] || 
     prevmt[1] < mt[1])
	{
		return false;
	}

  return true;
}

*/