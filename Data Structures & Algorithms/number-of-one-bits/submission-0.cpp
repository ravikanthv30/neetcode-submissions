class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int x = n;
        while (x>0)
        {
            //cout << x << " " << count << endl;
            if(x&1)
                count++;
            x= x>>1;
        }
        return count;
    }
};
