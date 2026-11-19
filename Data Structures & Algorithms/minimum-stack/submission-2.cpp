/*Yes, it is possible to solve the Min Stack problem using $O(1)$ auxiliary space (meaning only one stack instead of two).

You can achieve this by storing an **encoded value** in the stack whenever you find a new minimum. This encoded value acts as a mathematical "flag" that tells you two things when you pop it later:

1. That the minimum changed at this exact point.
2. What the *previous* minimum was before this point.

Because the math involves `2 * val - min_val`, you must use a `long long` for the stack to prevent integer overflow given the problem's constraints.

### The Math / Logic

Maintain a single stack of `long long` values and an integer `min_val`.

* **Push(val):**
* If the stack is empty, just push `val` and set `min_val = val`.
* If `val >= min_val`, push `val` normally.
* If `val < min_val` (a new minimum is found!), push the encoded value: **`2 * val - min_val`**. Then, update `min_val = val`.
* *Why this works:* Because `val < min_val`, the expression `2 * val - min_val` will always be **strictly less than** your new `min_val`. This anomaly (`stack.top() < min_val`) becomes our detectable flag.


* **Pop():**
* Peek at the top value.
* If `top < min_val`, you hit a flag! You are popping the element that changed the minimum. You must restore the previous minimum using the reverse formula: **`min_val = 2 * min_val - top`**.
* Pop the element.


* **Top():**
* If `top < min_val`, return `min_val` (because the actual value pushed *was* the current minimum).
* Otherwise, return `top` as normal.



### $O(1)$ Extra Space Implementation

```cpp
*/
class MinStack {
    stack<long long> st;
    long long min_val;

public:
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            min_val = val;
        } else if (val >= min_val) {
            st.push(val);
        } else {
            // Encode the new minimum flag
            st.push(2LL * val - min_val);
            min_val = val;
        }
    }
    
    void pop() {
        if (st.empty()) return;
        
        long long top = st.top();
        st.pop();
        
        if (top < min_val) {
            // Restore the previous minimum
            min_val = 2LL * min_val - top;
        }
    }
    
    int top() {
        long long top = st.top();
        if (top < min_val) {
            return min_val;
        }
        return top;
    }
    
    int getMin() {
        return min_val;
    }
};
/*

This trick completely eliminates the need for the second `min_st` stack while keeping all operations strictly $O(1)$ time.*/