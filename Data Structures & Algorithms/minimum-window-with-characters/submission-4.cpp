class Solution {
public:

 /*   bool isSubStr(auto &tar, auto &curr_counts, auto &target_counts)
    {
        for(auto c: tar)
        {
            if(!(curr_counts[c-'a'] >= target_counts[c-'a']))
                return false;
        }
        cout<<"yes substr"<<endl;
        return true;
    }
*/
    string minWindow(string s, string t) {
        // if t is longer than s, return ""
        string res = "";
        if(t.length() > s.length())
            return res;

//Solution notes:
// Input -> 2 strings s, t; o/p -> string - substring shortest
// for (s 0:s.len) --> for (t 0:t.len) --> form a substring when matching continue and break when its not
// optimal solution - I can use sliding window -> maintain a window --> add the char if it matches and remove not needed ones from the other side 
     /* 
        unordered_map<char, int> target_counts;
        for(char c : t) target_counts[c]++;
        string curr = "";
        int min_len = s.length();
        bool match = false;
        int l=0;
        unordered_map<char, int> curr_counts;
        for(int r=0;r<s.length(); r++)
        {
            char c=s[r];
            //add to the window
            curr.push_back(c);
            //is it valid ?
            curr_counts[c]++;
            
            //check if the window matches t
            if(target_counts[c] && target_counts[c] <= curr_counts[c])
            {
                
            }
            while( (curr.length() > t.length()))
            {
                bool shrink = true;
                for(int i=1; i< curr.length(); i++)
                {
                    char r = curr[i];
                    if( (curr_counts[r]) < (target_counts[r]) )
                    {
                        shrink = false;
                        break;
                    }
                }
                if(shrink)
                {
                    curr_counts[curr[0]]--;
                    curr.erase(0,1);
                    l++;
                    match = true;
                }
            }
            cout<<"curr:"<<curr<<endl;
            //find the min and save it 
            if( match && (min_len > curr.length()))
            {
                min_len = std::min(min_len, static_cast<int>(curr.length()));
                res = curr;
            }
        }
        return res; */
unordered_map<char, int> target_counts;
        for (char c : t) {
            target_counts[c]++;
        }

        unordered_map<char, int> curr_counts;
        int have = 0;
        int need = target_counts.size();

        int min_len = INT_MAX;
        int start_idx = 0;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            curr_counts[c]++;

            // Did this character satisfy target frequency?
            if (target_counts.count(c) && curr_counts[c] == target_counts[c]) {
                have++;
            }

            // Window is valid -> shrink from left to find minimal length
            while (have == need) {
                // Record the best window found so far
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start_idx = l;
                }

                // Remove character at left pointer
                char left_c = s[l];
                curr_counts[left_c]--;

                // If removing left_c breaks validity, decrement 'have'
                if (target_counts.count(left_c) && curr_counts[left_c] < target_counts[left_c]) {
                    have--;
                }

                l++; // Shrink window
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    

    } 
};
