class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int min = 1;
        for(auto num: nums)
        {
            if(num == min)
                min++;
            else if (num > min)
                break;
            else 
                continue;
        }

        return min;
    }
};