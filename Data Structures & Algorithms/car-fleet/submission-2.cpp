//input - [pos, speed], target miles
//output = number of groups reaching dest ?
// 1---4-------10
// 3   2        
// 9   6
// 3   3
//-----------
//0--1--4--7 ---> 10 //position
//1--2--2--1   //speed
//10 9  6  3   //target-pos
//10;4.5 3 3  //time taken (divide by speed)
//10 4.5 [3 3] //rounding if left is lesser than right & remove duplicates
//3 
//4  1  0  7
//3 4.5 10 3
//----------------
//target-pos/speed = time -> vector
//sort it via pos 
//rounding to right most position 
//group them and return num of groups --> size of set 
//edge cases: 

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
                int n = position.size();
        unordered_map <int, float> um;
        for(int i=0; i < n; i++)
        {
            float time =(float(target-position[i])/speed[i]);
            um.insert({position[i], time});
        }

        std::sort(position.begin(), position.end(), std::greater<int>());

        stack <float>st;

        for(auto i: position)
        {
            if(!st.empty())
            {
                if(st.top() >= um[i])
                    continue;
            }
            st.push(um[i]);
            cout<<"push"<<um[i]<<endl;
        }
        return st.size();
    }
};
