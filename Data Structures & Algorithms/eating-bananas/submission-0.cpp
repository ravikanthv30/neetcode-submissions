class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // in: pile[i] - num bananas ; h - max hrs ;
        // k rate
        // out: min k
        //BF: sort - for(k in p[0] to h ) -> check by get iterations 
        //Formula - 4*k + 62/k = h ==> 4k*k + sum = kh / hk-nk*k = sum 
        //variance/ diff = max - min 
        //sort input -> 25, 23, 10, 4 --> Max 4 
        //num of piles --> h > N  --> multiple times 
        //if h< N - error ; h==N ==> return max;
        //h> N ==> max_hops per pile = h/N => k = max_banans/max_hops = 4/3 = 1+1
        //binary search --> divide and search -> midpoint 
        
        int n = piles.size();
        if(h< n)
            return -1;
       // sort(piles.begin(), piles.end(), std::greater<int>() );


        int max_k = *max_element(piles.begin(), piles.end());
        int min_k = 1;
        int best_k = max_k;
        while(min_k <= max_k)
        {
           //check if can complete with current k
            long long hrs = 0;
            int k = (min_k + max_k)/2;
            for(int i =0; i<n;i++)
            {
                hrs += ceil(static_cast<double>(piles[i])/k);
            }
         cout<<"hrs:"<<hrs<<"k:"<<k<<"max k:"<<max_k<<"min_k:"<<min_k<<endl;
    
           if (hrs <=h)
           {
             best_k = k;
             max_k = k-1;
           }
            else
            {
             min_k = k+1;             
            }

        }
        //mean 25 23 10 4  // 21 
        // check - piles[i] - k <= 0 ==> ignore and do this will all array is 0 ; num_iter < h 
        //

        return best_k;
    }
};
