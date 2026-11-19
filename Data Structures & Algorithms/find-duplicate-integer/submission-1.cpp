class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //1-n // n+1 
        //BF:  Sort --> repating number --> return ;  Time: O(nlogn) space: O(1)
        //hashmap --> time: O(n) and space O(n)
        // add all of them -> n! - sum = X
        // val - index+1 == 0 else return that number ?
        //Array is unsorted and can be random order --> gone !! 
        // 

        //1 2 3 4 4 
        //0 1 2 3 4 
    /*    for(int i=0; i < nums.size(); i++)
        {
            if(abs(nums[i] - i) == 1)
            {
                continue;
            }
            return nums[i];
        }
        return -1; */

    //hashmap solution
    /*unordered_map <int, int> map;

    for(auto i:nums)
    {
        if(map[i])
            return i;
        else
            map[i]++;
    }
    return -1;
    } */

//it is immpossible to predict. 
// 1. detect if there is loop
//2. find the start of the loop and return it
    int slow = 0;
    int fast = 0;

    while(true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(slow == fast)
            break;
    }

    int slow2 = 0;
    while(true)
    {
        slow = nums[slow];
        slow2= nums[slow2];
        if(slow==slow2)
            return slow;
    }
    }
};
