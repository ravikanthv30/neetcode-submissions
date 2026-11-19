class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //buy = i ; sell= j
        //prices[i] < prices[j] ==> move i; if not move j 
        //for loop of for loop-> each price[j] - price[i] = curr_profit; 
        //max_profit = max (curr_p, max_p) 
        // buy = min of all 
        // sell = max of all 
        //
        int profit =0;
        int l=0, r=1;
        int curr_profit=0;
        int max_profit=0;
        while(r<prices.size())
        {
            if(prices[l] < prices[r])
            {
                curr_profit = prices[r] - prices[l] ;
                max_profit = max (curr_profit, max_profit);
            }
            else
                l=r;
            r++;

        }

        return max_profit;
    }
};
