class Solution {
public:
    int lengthOfLongestSubstring(string s) {
             unordered_map<char, int> m;
        int len=0;
        int max_len=0;
        for(int i=0; i<s.length(); i++)
        {
            //find if the same char is repeated or not in map 
            auto it = m.find(s[i]);
            if(it == m.end())
            {
              //if no, insert char, move to next 
                m.insert({s[i],i});
                len++;
                continue;
            }
            else
            {
            //if found, reset start to the index of the repeating char, reset m as well.
                if(max_len < len)
                    max_len = len;
                len = 0;
                //restart the index at i+1
                //abcdd
               // cout << max_len << " " << i << " " << it->second << " " <<endl;
                i = it->second;
                m.clear();
            }
            
        }
        if(max_len < len)
            max_len = len;
        //once visited all chars 
        return max_len; 
    }
};
