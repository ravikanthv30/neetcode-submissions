class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //1101 --> 110, 101
        bitset <32>res;
        int i =0;
        while(i<32)
        {
            if(n&1)
            res = res.set(32-i-1);
            n=n>>1;
            i++;
        }

        return (uint32_t)res.to_ulong();
    }
};
