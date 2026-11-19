class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //return iust max_length
        //BF: Sort array and go till sequence is broken -> max length  - O(nlogn) 
        //fixed numarray ; window ; hashmap 
        //find start of the sequence --> create vector everytime i find a new non consecutive number & return max of those vectors  // n vectors created.
        //hasmap start of sequence number and add length of it to it
        //2,3,4,4,5; 10; 20
        //0 1 1 2 3 4 5 6
        int max_len = 0;
        sort(nums.begin(), nums.end());
        //check min length is 2
        for(int i=0; i<nums.size(); i++)
        {
            int len=0;
            while((i<nums.size()-1) && ((nums[i]+1 == nums[i+1]) || (nums[i] == nums[i+1]) ) )
            {
                if(nums[i] != nums[i+1])
                {
                    len++;
                }
                i++;
                cout << i << nums[i]<< len <<endl;
            }
            
            max_len=max(max_len, len+1);
        }
        return max_len;
    }
};
