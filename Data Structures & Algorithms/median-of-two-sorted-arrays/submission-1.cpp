class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //BF - add elements in order and return median
        // WRONG -> mean = average = sum/num; 
        // median is middle value - find them mid index 
        // BF -> merge 2 sorted arrays and then find the middle value - O(n)
        long double median=0;
/*        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int n=nums1.size();
        int m = n/2;
        if( n%2 == 0)
            median = (nums1[m]+nums1[m-1])/2.0;
        else
            median = (nums1[m]);
        return median;
  */      
        // as both arrays are sorted --> can we do binary search on both and find the median and get average of it ?
        int n1=nums1.size();
        int n2=nums2.size();
        int j=0; int k=0;
        long double median1=0;
        for(int i =0 ; i<=(n1+n2)/2; i++)
        {
            median1 = median;
            if(j<n1 && k<n2)
            {
                median = min(nums1[j], nums2[k]);
                if(nums1[j] <= nums2[k])
                    j++;
                else 
                    k++;
            }
            else if(j<n1)
            {
                median=nums1[j];
                j++;
            }
            else if(k<n2)
            {
                median=nums2[k];
                k++;
            }
        }
        if((n1+n2)%2==0)
            return (median+median1)/2.0;
        else
            return median;

    }
};
