
//use actual stack to avoid memory access
//to do min value O(1) need to do extra space
//push [5, 2, 8]
//minStack = [5, 2, 2]
class MinStack {

    stack<int> st;
    stack<int> min_st;
public:
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        val = std::min(val,(min_st.empty()? val:min_st.top()));
        min_st.push(val);
    }
    
    void pop() {
        st.pop();
        //pop everytime as we always push lowest multiple times.
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        //how to get min in O(1)
      return min_st.top();
    }
};
