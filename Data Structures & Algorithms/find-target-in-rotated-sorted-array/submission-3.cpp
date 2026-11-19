class Solution {
public:
    int binarySearch(int target, vector<int>& nums, int l, int r)
    {
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m]==target)
                return m;
            else if(nums[m] < target)
            {
                //search in right
                l=m+1;
            }
            else if(nums[m] > target)
                r=m-1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
    //if it is default sorted array - do binary search - log n
    //as it is rotate - possibly start point is some where in middle
    // can I rotate the array first and then do the binary search ? 
    // rotation can be arleady o(n) solution ; cant meet o(logn)
    //-- can i find the pivot point via binary search ? yes 
    // once found search in left half and then search in right half
    int n=nums.size();
    int l =0;
    int r = n-1;
    //find pivot
    while(l<r)
    {
        int m = (l+r)/2;
        if(nums[m] > nums[r])
            l=m+1;
        else
            r=m;
    }
    int split = l;

    if(nums[split] == target)
        return split;
    int idx = binarySearch(target, nums, split, n-1);
    if(idx == -1)
        idx = binarySearch(target, nums, 0, split);
    return idx;
    }
};
