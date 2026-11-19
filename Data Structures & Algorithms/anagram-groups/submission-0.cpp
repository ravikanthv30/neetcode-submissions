class Solution {
public:

  bool isAnagram(string s, string t) {
        if (s.size() != t.size())
           return false;
       unordered_map<char, int> countS;
       unordered_map<char, int> countT;
       for(int i = 0; i < s.length(); i++)
       {
          countS[s[i]]++;
          countT[t[i]]++;
       }
    return countS==countT;
  }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> op;
        for(int i = 0; i < strs.size(); i++)
        {
            bool found = false;
            for(int j = 0; j < op.size(); j++)
            {
                //cout << "i: " << i << " j:" << j << "op" << op.size();
                if(isAnagram(strs[i], op[j][0]) )
                {
                    op[j].push_back(strs[i]);
                    found = true;
                    break;
                }

            }
            if (!found)
            {
                op.push_back({strs[i]});
            }
        }
        return op;
    }
};
