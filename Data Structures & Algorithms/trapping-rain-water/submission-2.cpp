class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        // Pointers starting at the absolute edges of the elevation map
        int l = 0;
        int r = height.size() - 1;
        
        // Track the highest walls seen so far from both directions
        int leftMax = height[l];
        int rightMax = height[r];
        int trappedWater = 0;
        
        while (l < r) {
            // If leftMax is smaller, the left side is the bottleneck.
            // Water at index 'l' is safely trapped up to leftMax, regardless of what is in the middle.
            if (leftMax < rightMax) {
                l++; // Move left pointer inward
                leftMax = max(leftMax, height[l]); // Update the highest wall seen on the left
                trappedWater += leftMax - height[l]; // Add trapped water at this specific column
            } 
            // If rightMax is smaller (or equal), the right side is the bottleneck.
            // Water at index 'r' is safely trapped up to rightMax.
            else {
                r--; // Move right pointer inward
                rightMax = max(rightMax, height[r]); // Update the highest wall seen on the right
                trappedWater += rightMax - height[r]; // Add trapped water at this specific column
            }
        }
        
        return trappedWater;
    }
};