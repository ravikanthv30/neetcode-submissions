class Solution {
public:
/*
    int trap(vector<int>& height) {


        if(height.size()<= 2)
            return 0;
        //h[i] --> l = i  go till next best where h[r] >= h[l] => count trap += ((min(l,r))*(r-l)) - sum(l+1 - r-1))
        int l=0;
        int r=1;
        int trap = 0;
        int sum=0;
        int h = height.size();
        while(r<h)
        {
            //find 2 non-consective non-zero numbers 
            //check if l>0 and then r>l
            //first increase = start 
            // end = next increasre till (>=l) -> I can check to include this or not 
            //if trap is there --> calculate 
            //l=0; r should go till r - r-1 decrease 
            // 0 2 0 3 1 
            // l = 1 1 
            // r = 2 3
            //sum= 0
            //trap=2

           // if(height[r] < height[r-1] || height[r] < height[l])
            //means we hit next increase //calculate trap 

            if( (l+1!=r) && height[r] >= height[l] )
            {
                //calculate trap;
                int minh = min(height[l], height[r]);
                int curr=(minh*(r-l-1) - (sum));
                trap= trap + curr;
                 cout<<"minh"<<minh<<"curr:"<<curr<<"trap:"<<trap<<endl;
                l=r;
                sum=0;
            }
            if((l!=r) && height[r] <= height[l])
            {
                sum+=height[r];
            }
            cout<<"l:"<<l<<"r:"<<r<<"sum:"<<sum<<"trap:"<<trap<<endl;
            if(height[l]==0)
                l++;
            r++;
        }
    return trap;

    }*/

int trap(vector<int>& height) {
    if (height.empty()) return 0;
    
    // 1. Find the highest peak
    int max_idx = 0;
    for (int i = 0; i < height.size(); i++) {
        if (height[i] > height[max_idx]) {
            max_idx = i;
        }
    }
    
    int total_trap = 0;
    
    // 2. Your logic: Left to Right (up to max_idx)
    int l = 0;
    int sum = 0;
    for (int r = 1; r <= max_idx; r++) {
        if (height[r] >= height[l]) {
            total_trap += (height[l] * (r - l - 1)) - sum;
            l = r;
            sum = 0;
        } else {
            sum += height[r];
        }
    }
    
    // 3. Your logic: Right to Left (down to max_idx)
    int right_boundary = height.size() - 1;
    sum = 0;
    for (int left_ptr = height.size() - 2; left_ptr >= max_idx; left_ptr--) {
        // Looking backwards, so we check if the left pointer is the new high wall
        if (height[left_ptr] >= height[right_boundary]) {
            total_trap += (height[right_boundary] * (right_boundary - left_ptr - 1)) - sum;
            right_boundary = left_ptr;
            sum = 0;
        } else {
            sum += height[left_ptr];
        }
    }
    
    return total_trap;
}
};