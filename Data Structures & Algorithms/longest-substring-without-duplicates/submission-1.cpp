#include <cstring>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array to store the "last seen" index of each character.
        // 128 covers all standard ASCII characters.
        int lastSeen[128];
        // Initialize with -1 to indicate the character hasn't been seen.
        memset(lastSeen, -1, sizeof(lastSeen));        
        int maxLen = 0;
        int l = 0; // Left boundary of our window
        
        for (int r = 0; r < s.length(); r++) {
            char currentChar = s[r];
            
            // If we've seen this char before AND it's inside our current window
            if (lastSeen[currentChar] >= l) {
                // JUMP the left pointer to the right of the previous occurrence
                l = lastSeen[currentChar] + 1;
            }
            
            // Update the last seen position to the current index
            lastSeen[currentChar] = r;
            
            // Calculate current window size and update max
            maxLen = max(maxLen, r - l + 1);
        }
        
        return maxLen;
    }
};