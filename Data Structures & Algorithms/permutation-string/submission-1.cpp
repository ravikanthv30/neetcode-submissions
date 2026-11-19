
//abc
//lecaabee 
//um - a d c
// d --> sm - d 
// c --> sm - d c
// d --> sm - d
// ret true
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       /* 
        unordered_map <char, int> um;
        for(auto c:s1)
            um[c]++;
        unordered_map <char, int> sm;
        for(auto c:s2)
        {
            bool match =false;
            cout<<"sm" <<sm.count(c) <<"um" <<um.count(c)<<endl;
            if( um.count(c) && (sm.count(c) < um.count(c)))
            {
                sm[c]++;
                match = true;
            }       
            if(!match)
            {
                sm.clear();
            }
            if(sm == um)
                return true;

        }
        return false;
        
    } */
    unordered_map<char, int> um;
        for (char c : s1) um[c]++;

        unordered_map<char, int> sm;
        int l = 0;

        for (int r = 0; r < s2.size(); r++) {
            char c = s2[r];
            sm[c]++;

            // Shrink from the left if current char exceeds what's allowed in s1
            while (sm[c] > um[c]) {
                sm[s2[l]]--;
                l++;
            }

            // If the valid window length matches s1, we found a permutation
            if (r - l + 1 == s1.size()) return true;
        }

        return false;
    }
};
