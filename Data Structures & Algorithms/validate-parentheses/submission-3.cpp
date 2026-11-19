class Solution {
public:
    bool match(char a, char b)
    {
        if(   a=='(' && b==')'
           || a=='[' && b==']'
           || a=='{' && b=='}')
           return true;
        else
            return false;
    }
    bool isValid(string s) {
        //two pointer approach for the brackets ? to see its palindrom ?
        //BF: Run 2 loops and come from back to front 
  /*      for(int i = 0; i<s.length(); i++)
        {
            for(int j =s.length()-1; j>i j--)
            {
                if (s[j] != s[i])
                    return false;
            }
        }*/
        stack <char> st;
        for(auto c:s)
        {
            if(c=='(' || c=='['|| c=='{')
                st.push(c);
            else if (c==')' || c==']'|| c=='}')
            {
                if(st.size()==0)
                    return false;                
                char p = static_cast<char>(st.top());
                cout<<c << p <<endl;
                if (!match(p,c))
                    return false;
                st.pop();
            }
        }
        if(st.size()==0)
            return true;
        return false;
    }
};
