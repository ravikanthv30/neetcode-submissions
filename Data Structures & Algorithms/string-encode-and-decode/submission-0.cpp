class Solution {
public:

    string encode(vector<string>& strs) {
        //algo -> substract the base 'a' for each and then store 
        //as 8bit is occupied with 256 char already we cannot do - or + which can cause overflow till end
        //encoding is to pacakge the strings.. so have a number of char as first and end with seperator
        #define SEP '#'
        string enc ="";
        int s=0;
        //vector of strings -> run a loop and convert each and have seperator defined
        //seperator should be outside of the ASCII can reach --> 255 ? 
        for(int i=0;i<strs.size();i++)
        {
            enc += std::to_string(strs[i].length());
            // 2. Append the separator character '#'
            enc += '#';
            // 3. Append the actual string content
            enc += strs[i];
        }

        return enc;
    }

    vector<string> decode(string s) {
        vector<string> strs={};
        int i=0;
        int j=0;
        while(i<s.length())
        {
            //read till #
            int j = i;
            while(s[j] != '#' && j < s.length())
                j++;
            int len = stoi(s.substr(i, j-i));

            if(j+len < s.length())
            {
                string dec1 = "";
                dec1 += s.substr(j+1, len);
                strs.push_back(dec1);
            }
            i=j+len+1;
        }
        return strs;
    }
};
