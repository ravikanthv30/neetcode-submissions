#include <cstring>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        unordered_map<char,int> m;
        //start l and r at same point
        int l=0;
        //Keep l constant and move only r
        for(int r=0; r<s.length(); r++)
        {
            //try to find if the r char is already there in map
            while(m.find(s[r]) != m.end())
            {
            //if yes, then remove the left side char and move to next l
            //then try to find if r char is still repeated again? and get to l where r is not there at all
               m.erase((char)s[l]);
               l++;                
            }
            //if NO, then add r char to map and move r to next char
            m[s[r]]++;
            //as are moving r, before that, curret r char is good to be incl
            //so check if max_len vs new substring which one is long
            max_len = max(max_len, r-l+1);
        }
    return max_len;
    }
};