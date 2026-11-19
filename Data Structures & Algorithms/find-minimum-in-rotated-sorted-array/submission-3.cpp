class Solution {
public:
    int findMin(vector<int> &nums) {
        
        // rotated sorted array  - return min number 
        // BF -> sort again and get min 
        // return the first element where it derements -> that would be least if not return 1st 
        //first check if last > first 
        //else take mid and find same anamoly -> mid < first ; last > mid -> search here in one of that 
        int ret = INT_MAX;
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            if(nums[l]<nums[r])
            {
               ret = min(ret, nums[l]);
               break;
            }
            int mid =  (l + r) / 2;
            ret = min(ret, nums[mid]);

            if(nums[mid] >= nums[l])
                l=mid+1;
            else
                r=mid-1;

           // cout<<l<<" "<<r<<" "<<mid<<" "<<nums[l]<<" "<<nums[r]<<" "<<endl;
        }
        return ret;
    }
};
