class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //is this always sorted ? if so i can go with for loop and return 

        int sum = nums.size();
        for(int i=0; i<nums.size(); i++)
        {
          //  sum+=nums[i];
          sum=sum^i^nums[i];
        }
        //return (((n*(n+1))/2)-sum);
        return sum;

    }
};
