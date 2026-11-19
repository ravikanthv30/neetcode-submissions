class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //BF - add elements in order and return median
        // WRONG -> mean = average = sum/num; 
        // median is middle value - find them mid index 
        // BF -> merge 2 sorted arrays and then find the middle value - O(n)
        long double median=0;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int n=nums1.size();
        int m = n/2;
        if( n%2 == 0)
            median = (nums1[m]+nums1[m-1])/2.0;
        else
            median = (nums1[m]);
        
        return median;
        
        // as both arrays are sorted --> can we do binary search on both and find the median and get average of it ?


    }
};
