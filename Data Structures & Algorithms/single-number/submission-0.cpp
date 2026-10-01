class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //BF - hasmap but o(n) space 
        //sort -> o(nlogn)
        // need solution inplace --> n & n! = 0
        //101 101 11 XOR
        int res =0;
        for(auto i : nums)
        {
            res = (i ^ res);
        }
        return res;

    }
};
