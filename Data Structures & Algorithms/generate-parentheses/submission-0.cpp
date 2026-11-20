class Solution {
public:
 // number and return list of paranthese combinations 
    vector<string> generateParenthesis(int n) {
        vector <string> res;
        if(n==0)
            return res;
        // n -> n*2 is the actual array length 
        // first always ( and then )
        // evry position -> 1 choice of ( ; if onum > cnum -> 3 choices = 0
        //n==0 -> add to res 
        // ( - n=2; len<n -> add close ;  n=1 (
        string s;
        backtrack(n, 0, 0, s, res);
        return res;
    }
private:
    void backtrack(const int n, int oc, int cc, string & s, vector <string> & res)
    {
        if(static_cast<int>(s.size()) == n*2)
        {
            res.push_back(s);
            return;
        }

        //pick '(' only if first, ran out of ')'
        //pick ')' if n==0 or n>cnum
        //for loop here I think
        if(oc < n)
        {
            s.push_back('(');
            backtrack(n, oc+1, cc, s, res);
            s.pop_back();
        }

        if(cc < oc)
        {
            s.push_back(')');
            backtrack(n, oc, cc+1, s, res);
            s.pop_back();
        }
    }
};
