class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack <int> st;

        for(auto i : tokens)
        {
            if(! ((i == "+") || (i == "*") || (i == "/") ||(i == "-")) )
            {
                //assume it is digit - push to st
                st.push(stoi(i));
            }
            else
            {
                int a=0, b=0;
                if(st.size() >= 2)
                {
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    int res = 0;

                    if(i == "+")
                        res = a+b;
                    else if(i == "-")
                        res = a-b;
                    else if(i == "*")
                        res = a*b;
                    else if(i == "/")
                        res = int(a/b);
                    else
                        return -1;            

                    st.push(res);
                }
            }
        }
        if(st.size()==1)
            return int(st.top());
        else 
            return -1;
    }
};
