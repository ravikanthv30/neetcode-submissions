class Solution {
public:
    int search(vector<int>& nums, int target) {
        //checks
        //corner case validations
        //BF-> run through all the in a for loop and return if found
        //optimized -> Heap sort kind of where directly go to middle and travese from there to go other half
        int ret = -1;
        if(nums.size() ==0)
            return ret;
        if(nums.size() == 1)
            return (nums[0]==target)?0:ret;
        
        //recursion is one way to do ; while loop
        int i = 0;
        int j = nums.size()-1;
        //i=0->1 , j =5 
        while (i<=j)
        {
            int mid= abs((i+j)/2);
          //  cout<<i <<" "<< mid <<" "<< j<<endl;
            //mid=2 - 2; 3
            if(target == nums[mid])
            {
                ret = mid;
                break;
            }
            else if(target < nums[mid])
            {
               //start in the other half
                j=mid-1;
            }
            else
            {
                //search in other half
                i=mid+1;
            }
        }
        return ret;
    }
};
