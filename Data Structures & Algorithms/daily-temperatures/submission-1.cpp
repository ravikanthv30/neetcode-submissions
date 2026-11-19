//so we need to get next higher number from current position and get the index to that  
// BF: O(n2) 2 for loops and get each index 
// [30,38,30,36,35,40,28]
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector <int> res(n);
        stack <pair<int,int>> st;
        for(int i=0; i< n; i++)
        {
            int temp = temperatures[i];
            while(!st.empty() && (temp > st.top().first))
            {
                //remove from stack 
                auto pair = st.top();
                st.pop();
                res[pair.second] = i - pair.second;
            }

            st.push({temp, i});
        }
        return res;
    }
};
