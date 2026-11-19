class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
                
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>= nums.size())
                continue;
            while(nums[i] > 0 && nums[i] < i+1 && nums[nums[i]-1] != nums[i])
            {
                //swap the numbers if not in right place
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};