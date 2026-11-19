class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int res = 0;
        int curr_sum=0;
        int max_sum=INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            curr_sum = max(curr_sum+nums[i], nums[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};


//for followup question like return index of the array
/*
class Solution {
public:
    pair<int, int> maxSubArrayIndices(vector<int>& nums) {
        int curr_sum = 0;
        int max_sum = INT_MIN;
        int start = 0, end = 0;
        int best_start = 0, best_end = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            // Decide: start fresh at i, or extend the previous window?
            if (curr_sum + nums[i] < nums[i]) {
                start = i;
            }
            end = i;

            curr_sum = max(curr_sum + nums[i], nums[i]);

            // Snapshot the window only when we beat the best sum so far
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                best_start = start;
                best_end = end;
            }
        }
        return {best_start, best_end};
    }
};
*/