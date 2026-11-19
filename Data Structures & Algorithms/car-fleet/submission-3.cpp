class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

      vector <pair<int, double>> cf;
      int n  = position.size();
        double val=0;
      for(int i=0; i<n; i++)
      {
        val = (double(target-position[i])/speed[i]);
        cf.push_back({position[i], val});
      } 

      sort(cf.rbegin(), cf.rend());
      //sort(cf.begin(), cf.end(), [](const auto&a, const auto&b){return a.first < b.first;});
        stack <double> st;
        for(auto t: cf)
        {
            double curr_time = t.second;
            if(st.empty() || curr_time > st.top())
            {
                st.push(curr_time);
            }
        }
        return st.size();
    }
};
