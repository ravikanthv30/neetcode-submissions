class Solution {
public:
    int maxArea(vector<int>& heights) {
        //checks and assumptions - 
        //problem: select 2 highest and fartest numbers 
        //7&6(h) -> 6 distance(l) --> water = h*l
        //BF - get all the area catputed in 2 for loop and select max
        //Solution- use two pointers start from last and go over to see what max can be
        //max - H and max l 

        int l =0;
        int r = heights.size()-1;
        int res = 0;
        while(l<r)
        {
            int area =((min(heights[l],heights[r])) * (r-l));
            res = max(res,area);
            if(heights[l]<=heights[r])
            {
                l++;
            }
            else 
            {
                r--;
            }
        }
        return res;
    }
};
