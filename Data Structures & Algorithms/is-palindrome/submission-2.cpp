class Solution {
public:
    bool isPalindrome(string s) {
        //two index to come from back and forth 
        //ignore non-alphanermeric 
        int i = 0; 
        int j = s.length()-1;
        bool ret = true;

        while(i<j)
        {
            while(i< s.length() && !isalnum(s[i]))
                i++;
            while(j>0 &&  !isalnum(s[j]))
                j--;
            if(i>j)
                break;
          //  cout << "si:" << s[i] << "sj:"<<s[j]<<endl;
            if(tolower(s[i]) != tolower(s[j]))
            {
                ret = false;
              //  cout << "i:" << i << "j:"<<j <<endl;
                break;
            }
            j--;
            i++;
        }

    return ret;
    }
};
