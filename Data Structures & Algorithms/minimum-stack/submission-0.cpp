
//so idea here is to get these fucntions implemented in O(1) and get alwasy have min on top ? - NO
// so standard and I can use some vector to do this and remove from edge always 
//getMin() - can i store the min value seperatly in variable.
class MinStack {
    //int min_val = INT_MAX;
    vector<int> st;
public:
    MinStack() {
        st.empty();
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st[st.size()-1];
    }
    
    int getMin() {
        //how to get min in O(1)
       int min_val = INT_MAX;
        for(int i=0;i<st.size(); i++)
        {
            if (min_val > st[i])
            {
                min_val=st[i];
            }
        }
        return min_val;
    }
};
