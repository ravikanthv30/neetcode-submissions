class Solution {
public:
    int getSum(int a, int b) {
        //a|b ; ab&b
        //2 - 10 3 11
        //5 101
        //s1 - take first 2 bits | them 
        //s2 - if both are 1 - add to c 
        //s3 -
        while(b!=0)
        {
            int c = (a&b) <<1;
            a = a^b;
            b = c;
        }
        return a;
    }
};
