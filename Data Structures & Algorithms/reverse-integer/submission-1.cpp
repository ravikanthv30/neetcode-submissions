class Solution {
public:
    int reverse(int x) {
        //32bit integer -> 456 - 654 ; INT_MAX 65535 - FF FF FF FF - sign storage ?
        //1234 - 0000 0100 1101 0010
        //4321 - 0001 0000 1110 0001

        //-4321  1110 1111 0001 1111
        //-1234  1111 1011 0010 1110

        //BF: extract each digit -> and reverse keep the sign; if more than 65535 return 0
        if(abs(x) > INT_MAX || abs(x) <= 0)
            return 0;
        int sign = 1;
        if(x<0)
            sign = -1;
        x=abs(x);
        int ret=0;
        while(x)
        {
            int d = x%10;
            if(ret > INT_MAX/10 || ret==INT_MAX/10 && d>7)
                return 0;
            ret = ret*10 + d;
            x=x/10;
        };
        //x - 90, d=0, ret =0 // x-9
        return sign*ret;

    }
};
