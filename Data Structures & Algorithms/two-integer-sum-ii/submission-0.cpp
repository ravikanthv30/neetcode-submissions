class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //checks - NO additional spaces, already sorted, return also sorted 
        //corner cases 
        //BF: 2 for loops -> i+j = taget, return i,j 
        //optimal - cannot use hash due to space; two pointer approach 
        //start l and r from both the ends and move based on the target
        //as input array is already sorted --> we can move easily 
        int l =0;
        int r=numbers.size()-1;
        vector<int> res;
        while(l<=r)
        {
            if(numbers[l]+numbers[r] == target)
            {
                res.push_back(l+1);
                res.push_back(r+1);
                return res; 
            }
            else if(numbers[l]+numbers[r] < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return res;
    }
};
