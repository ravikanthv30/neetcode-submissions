class Solution {
public:

    int getBits(int n)
    {
        int ones = 0;
        while(n!=0)
        {
            if(n&1) 
                ones++;
            n = n>>1;
        }
        return ones;
    };
    vector<int> countBits(int n) {
        
        vector <int> res(n+1);

        for(int i=0; i<=n; i++)
        {
            res[i] = getBits(i);
        }
        return res;
    }
};
