class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //checks
        //corner cases 
        //BF: do a for loop for all matrix and search 
        //Solution: As each of the rows are sorted and first column is also sorted
        //can find which row to search by doing a search in first row.
        //find the row by seatching in the first column
        int l=0;
        int h=matrix.size()-1;
        int mid =0;
        while(l<=h)
        {
            mid= abs((l+h)/2);
            if(target == matrix[mid][0])
            {
                return true;
            }
            else if(target < matrix[mid][0])
            {
                //start in the other half
                h=mid-1;
            }
            else
            {
                //search in other half
                l=mid+1;
            }
        }
        //figure out which one to use b/w l, m, h
        int row = h;
        if (row < 0) return false;
        auto it = find(matrix[row].begin(), matrix[row].end(),target);
        return (it != matrix[row].end());
        
    }
};
