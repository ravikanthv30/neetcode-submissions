class Solution {
public:
    int characterReplacement(string s, int k) {
        //can replace K chars
        //return length of longest unique repeating char

        //GET most and least freq char of that window
        //GET longest repeating seq - increase the window
        //ACTION: check if window is within K replacements 
        //RETURN: longest length SS

        //BF: 2 for loops identify first longest repating char and replace near by ?
        //Coditions to handle: completely unique string with no char repating
        unordered_map<char,int> m;
        int l=0;
        int res=0;
        int maxF=0;
        for(int r=0; r < s.length(); r++)
        {
            //add r char to map
            m[s[r]]++;
            maxF = max(maxF, m[s[r]]);
            //if char not found means it is different
            // allow within the K 
            while((r-l+1)-maxF>k)
            {
                // 4. Shrink the window from the left
                m[s[l]]--; // Decrement the count of the character leaving the window
                l++;       // Move left pointer forward
            }
  
            res = max(res, r-l+1);
            //add to substring 
        }
        return res;
    }
};
