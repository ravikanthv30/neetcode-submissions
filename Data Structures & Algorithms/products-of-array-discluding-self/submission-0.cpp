class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //checks & assumptions - 
        //i/o array
        //BF- 2 for loops multiply 
        //solution: as we access the numbers multiply them ?
        int i=0;
        int n=nums.size();
        int j=n-1;
        vector <int> res(n,1);

/*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)            
            {
                if(j!=i)
                {
                    res[j] = res[j]*nums[i];
                }
            }
        }
*/
        int pp=1;
        for(int i=1;i<n;i++)
        {
            pp*=nums[i-1];
            res[i]=res[i]*pp;
            
        }
        pp=1;
        for(int i=n-2;i>=0;i--)
        {
            pp=pp*nums[i+1];
            res[i]=res[i]*pp;            
        }
        return res;

    }
};
